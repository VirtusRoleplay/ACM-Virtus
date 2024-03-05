#include "..\script_component.hpp"
/*
 * Author: Glowbal
 * Calculates the blood volume change and decreases the IVs given to the unit.
 *
 * Arguments:
 * 0: The Unit <OBJECT>
 * 1: Time since last update <NUMBER>
 * 2: Global Sync Values (bloodbags) <BOOL>
 *
 * Return Value:
 * Blood volume <NUMBER>
 *
 * Example:
 * [player, 1, true] call ace_medical_status_fnc_getBloodVolumeChange
 *
 * Public: No
 */

params ["_unit", "_deltaT", "_syncValues"];

//private _effectiveBloodVolume = GET_BLOOD_VOLUME(_unit); // TODO unused?

private _bloodVolume = _unit getVariable [QEGVAR(circulation,Blood_Volume), 6];
private _plasmaVolume = _unit getVariable [QEGVAR(circulation,Plasma_Volume), 0];
private _salineVolume = _unit getVariable [QEGVAR(circulation,Saline_Volume), 0];

private _bloodVolumeChange = 0;
private _plasmaVolumeChange = 0;
private _salineVolumeChange = 0;

private _activeVolumes = 0;

private _bloodLoss = -_deltaT * GET_BLOOD_LOSS(_unit);

if (_bloodVolume > 0) then {
    _activeVolumes = _activeVolumes + 1;
};

if (_plasmaVolume > 0) then {
    _activeVolumes = _activeVolumes + 1;
};

if (_salineVolume > 0) then {
    _activeVolumes = _activeVolumes + 1;
};

if (_bloodVolume > 0) then {
    _bloodVolumeChange = _bloodLoss / _activeVolumes;
};

if (_plasmaVolume > 0) then {
    _plasmaVolumeChange = _bloodLoss / _activeVolumes;
};

if (_salineVolume > 0) then {
    _salineVolumeChange = _bloodLoss / _activeVolumes;
};

if (!isNil {_unit getVariable QACEGVAR(medical,ivBags)}) then {
    private _flowMultiplier = 1;

    if (IN_CRDC_ARRST(_unit)) then {
        _flowMultiplier = 0.02;
        if (alive (_unit getVariable [QACEGVAR(medical,CPR_provider), objNull])) then {
            _flowMultiplier = 0.6;
        };
    };

    private _bloodBags = _unit getVariable [QACEGVAR(medical,ivBags), []];
    private _tourniquets = GET_TOURNIQUETS(_unit);

    _bloodBags = _bloodBags apply {
        _x params ["_bagVolumeRemaining", "_type", "_bodyPart"];

        if (_tourniquets select _bodyPart == 0) then {

            private _fluidFlowRate = 1;

            switch (_type) do {
                case "Blood": {
                    _fluidFlowRate = 0.8;
                };
                case "Saline": {
                    _fluidFlowRate = 1.2;
                };
                default {};
            };

            private _bagChange = ((_deltaT * ACEGVAR(medical,ivFlowRate) * ([_unit, _bodypart] call EFUNC(circulation,getIVFlowRate))) * _flowMultiplier * _fluidFlowRate) min _bagVolumeRemaining; // absolute value of the change in miliLiters
            _bagVolumeRemaining = _bagVolumeRemaining - _bagChange;

            switch (_type) do {
                case "Plasma": {
                    _plasmaVolumeChange = _plasmaVolumeChange + (_bagChange / 1000);
                };
                case "Saline": {
                    _salineVolumeChange = _salineVolumeChange + (_bagChange / 1000);
                };
                default {
                    _bloodVolumeChange = _bloodVolumeChange + (_bagChange / 1000);
                };
            };
        };

        if (_bagVolumeRemaining < 0.01) then {
            []
        } else {
            [_bagVolumeRemaining, _type, _bodyPart]
        };
    };

    _bloodBags = _bloodBags - [[]]; // remove empty bags

    if (_bloodBags isEqualTo []) then {
        _unit setVariable [QACEGVAR(medical,ivBags), nil, true]; // no bags left - clear variable (always globaly sync this)
    } else {
        _unit setVariable [QACEGVAR(medical,ivBags), _bloodBags, _syncValues];
    };
};

if (_bloodVolume < 6) then {
    if (_plasmaVolume + _plasmaVolumeChange > 0) then {
        private _leftToConvert = _plasmaVolume + _plasmaVolumeChange;
        private _conversionRate = (-_deltaT * (2 / 1000)) min _leftToConvert;
    
        _plasmaVolumeChange = _plasmaVolumeChange + _conversionRate;
        _bloodVolumeChange = _bloodVolumeChange - _conversionRate;
    };
    
    if (_salineVolume + _salineVolumeChange > 0) then {
        private _leftToConvert = _salineVolume + _salineVolumeChange;
        private _conversionRate = (-_deltaT * (0.5 / 1000)) min _leftToConvert;
        
        _salineVolumeChange = _salineVolumeChange + _conversionRate;
        _bloodVolumeChange = _bloodVolumeChange - _conversionRate;
    };
};

_bloodVolume = 0 max _bloodVolume + _bloodVolumeChange min DEFAULT_BLOOD_VOLUME; 
_plasmaVolume = 0 max _plasmaVolume + _plasmaVolumeChange min DEFAULT_BLOOD_VOLUME; 
_salineVolume = 0 max _salineVolume + _salineVolumeChange min DEFAULT_BLOOD_VOLUME;

private _fluidOverload = 0 max ((_bloodVolume + _plasmaVolume + _salineVolume) - 6);

_unit setVariable [QEGVAR(circulation,Blood_Volume), _bloodVolume, _syncValues];
_unit setVariable [QEGVAR(circulation,Plasma_Volume), _plasmaVolume, _syncValues];
_unit setVariable [QEGVAR(circulation,Saline_Volume), _salineVolume, _syncValues];

_bloodVolume + _plasmaVolume + _salineVolume min DEFAULT_BLOOD_VOLUME; 