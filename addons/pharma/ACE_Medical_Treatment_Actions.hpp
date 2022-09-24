class ACE_Medical_Treatment_Actions {
    class BasicBandage;
    class FieldDressing;
    class ApplyTourniquet;
    class RemoveTourniquet;
    class Morphine;
    class CheckPulse;
    class CPR;

    class BloodIV: BasicBandage {
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        medicRequired = QUOTE(ace_medical_treatment_medicIV);
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(RequireInsIV)));
    };
    class Epinephrine: Morphine{
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Painkillers: Morphine {
        displayName = CSTRING(Inject_Box_Painkillers);
        displayNameProgress = CSTRING(Using);
        allowedSelections[] = {"Head"};
        items[] = {};
        callbackSuccess = QFUNC(treatmentAdvanced_Painkillers);
        condition = "[_medic, 'kat_Painkiller'] call ace_common_fnc_hasMagazine || [_patient, 'kat_Painkiller'] call ace_common_fnc_hasMagazine";
        litter[] = {};
        icon = QPATHTOF(ui\icon_painkillers_action.paa);
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
    };
    class Carbonate: Morphine {
        displayName = CSTRING(Take_Carbonate);
        displayNameProgress = CSTRING(Using);
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Carbonate);
        treatmentTime = QGVAR(treatmentTime_Carbonate);
        items[] = {};
        litter[] = {};
        condition = "[_medic, 'kat_Carbonate'] call ace_common_fnc_hasMagazine || [_patient, 'kat_Carbonate'] call ace_common_fnc_hasMagazine";
        callbackSuccess = QFUNC(treatmentAdvanced_Carbonate);
    };
    class Naloxone: Carbonate {
        displayName = CSTRING(Take_Naloxone);
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Naloxone);
        treatmentTime = QGVAR(treatmentTime_Naloxone);
        items[] = {"kat_naloxone"};
        condition = "true";
        callbackSuccess = QFUNC(treatmentAdvanced_Naloxone);
    };
    class EACA: Carbonate {
        displayName = CSTRING(Take_EACA);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_EACA);
        treatmentTime = QGVAR(treatmentTime_EACA);
        items[] = {"kat_EACA"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_EACA);
    };
    class TXA: Carbonate {
        displayName = CSTRING(Take_TXA);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_TXA);
        treatmentTime = QGVAR(treatmentTime_TXA);
        items[] = {"kat_TXA"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_TXA);
    };
    class SalineFlush: Carbonate {
        displayName = CSTRING(Saline_Flush);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = 1;
        treatmentTime = 3;
        items[] = {};
        condition = QUOTE((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(salineCheck));
        callbackSuccess = QFUNC(treatmentAdvanced_Flush);
    };
    class Inspect: Carbonate {
        displayName = CSTRING(Inspect_Catheter);
        category = "examine";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = 1;
        treatmentTime = 2;
        items[] = {};
        condition = QFUNC(removeIV);
        callbackSuccess = QFUNC(inspectCatheter);
        animationMedic = "";
        animationMedicProne = "";
    };
    class BreathCheck: Carbonate {
        displayName = CSTRING(Check_Breath);
        category = "examine";
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 1;
        medicRequired = 1;
        treatmentTime = 2;
        items[] = {};
        condition = true;
        callbackSuccess = QFUNC(inspectBreath);
        animationMedic = "";
        animationMedicProne = "";
    };
    class Norepinephrine: Carbonate {
        displayName = CSTRING(Take_Norep);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Norepinephrine);
        treatmentTime = QGVAR(treatmentTime_Norepinephrine);
        items[] = {"kat_norepinephrine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Phenylephrine: Carbonate {
        displayName = CSTRING(Take_Phenyl);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Phenylephrine);
        treatmentTime = QGVAR(treatmentTime_Phenylephrine);
        items[] = {"kat_phenylephrine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Nitroglycerin: Carbonate {
        displayName = CSTRING(Take_Nitro);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Nitroglicerin);
        treatmentTime = QGVAR(treatmentTime_Nitroglycerin);
        items[] = {"kat_nitroglycerin"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Amiodarone: Carbonate {
        displayName = CSTRING(Take_Amiodarone);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Amiodarone);
        treatmentTime = QGVAR(treatmentTime_Amiodarone);
        items[] = {"kat_amiodarone"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Amiodarone);
    };
    class Lidocaine: Carbonate {
        displayName = CSTRING(Take_Lidocaine);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Lidocain);
        treatmentTime = QGVAR(treatmentTime_Lidocaine);
        items[] = {"kat_lidocaine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Atropine: Carbonate {
        displayName = CSTRING(Take_Atropine);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Atropine);
        treatmentTime = QGVAR(treatmentTime_Atropine);
        items[] = {"kat_atropine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Atropine);
    };
    class Ketamine: Carbonate {
        displayName = CSTRING(Take_Ketamine);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Ketamine);
        treatmentTime = QGVAR(treatmentTime_Ketamine);
        items[] = {"kat_ketamine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Ketamine);
    };
    class Fentanyl: Carbonate {
        displayName = CSTRING(Take_Fentanyl);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Fentanyl);
        treatmentTime = QGVAR(treatmentTime_Fentanyl);
        items[] = {"kat_fentanyl"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Fentanyl);
    };
    class Nalbuphine: Carbonate {
        displayName = CSTRING(Take_Nalbuphine);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Nalbuphine);
        treatmentTime = QGVAR(treatmentTime_Nalbuphine);
        items[] = {"kat_nalbuphine"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Nalbuphine);
    };
    class Reorientation: Carbonate {
        displayName = CSTRING(Take_Reorient);
        displayNameProgress = CSTRING(Reorienting);
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_Reorientation);
        treatmentTime = QGVAR(treatmentTime_Reorientation);
        items[] = {};
        condition = QUOTE(!([_patient] call ace_common_fnc_isAwake) && GVAR(Reorientation_Enable));
        litter[] = {};
        callbackSuccess = QFUNC(treatmentAdvanced_Reorientation);
        animationMedic = "AinvPknlMstpSnonWnonDnon_medicUp4";
        animationMedicProne = "AinvPknlMstpSnonWnonDnon_medicUp4";
    };
    class ApplyIV: ApplyTourniquet {
        displayName = CSTRING(Apply_IV_16);
        displayNameProgress = CSTRING(Applying_IV);
        medicRequired = QGVAR(medLvl_ApplyIV);
        category = "advanced";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        items[] = {"kat_IV_16"};
        condition = QUOTE((!(_patient getVariable [ARR_2(QQGVAR(IVplaced), false)])) && FUNC(checkIV));
        treatmentTime = QGVAR(treatmentTime_ApplyIV);
        callbackSuccess = QUOTE([ARR_4(_player, _patient, _bodyPart, 'kat_IV_16')] call FUNC(applyIV));
        litter[] = {};
    };
    class ApplyIO: ApplyIV {
        displayName = CSTRING(Apply_IO_45);
        displayNameProgress = CSTRING(Applying_IV);
        medicRequired = QGVAR(medLvl_ApplyIO);
        category = "advanced";
        allowedSelections[] = {"Body"};
        items[] = {"kat_IO_FAST"};
        condition = QUOTE(!(_patient getVariable [ARR_2(QQGVAR(IVplaced), false)]));
        treatmentTime = QGVAR(treatmentTime_ApplyIO);
        callbackSuccess = QUOTE([ARR_4(_player, _patient, _bodyPart, 'kat_IO_FAST')] call FUNC(applyIV));
        litter[] = {};
    };
    class RemoveIV: ApplyTourniquet {
        displayName = CSTRING(Remove_IV);
        displayNameProgress = CSTRING(Removing_IV);
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        treatmentTime = 3;
        items[] = {};
        condition = QFUNC(removeIV);
        callbackSuccess = QFUNC(retrieveIV);
    };
    class Etomidate: Carbonate {
        displayName = CSTRING(Etomidate_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_Etomidate);
        treatmentTime = QGVAR(treatmentTime_Etomidate);
        items[] = {"kat_etomidate"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_medication);
    };
    class Lorazepam: Carbonate {
        displayName = CSTRING(Lorazepam_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_Lorazepam);
        treatmentTime = QGVAR(treatmentTime_Lorazepam);
        items[] = {"kat_lorazepam"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Lorazepam);
    };
    class Flumazenil: Carbonate {
        displayName = CSTRING(Flumazenil_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_Flumezenil);
        treatmentTime = QGVAR(treatmentTime_Flumazenil);
        items[] = {"kat_flumazenil"};
        condition = QUOTE(((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(removeIV)) || !(GVAR(MedicationsRequireInsIV)));
        callbackSuccess = QFUNC(treatmentAdvanced_Flumazenil);
    };
};
