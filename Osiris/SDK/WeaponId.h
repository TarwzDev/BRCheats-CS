#pragma once

enum class WeaponId : short {
    Deagle = 1,
    Elite,
    Fiveseven,
    Glock,
    Ak47 = 7,
    Aug,
    Awp,
    Famas,
    G3SG1,
    GalilAr = 13,
    M249,
    M4A1 = 16,
    Mac10,
    P90 = 19,
    ZoneRepulsor,
    Mp5sd = 23,
    Ump45,
    Xm1014,
    Bizon,
    Mag7,
    Negev,
    Sawedoff,
    Tec9,
    Taser,
    Hkp2000,
    Mp7,
    Mp9,
    Nova,
    P250,
    Shield,
    Scar20,
    Sg553,
    Ssg08,
    Knife = 42,
    Flash,
    HEGrenade,
    SmokeGrenade,
    Molotov,
    Decoy,
    IncGrenade,
    C4,
    Healthshot = 57,
    GoldenKnife,
    KnifeT = 59,
    M4a1_s = 60,
    Usp_s,
    Cz75a = 63,
    Revolver,
    TaGrenade = 68,
    Axe = 75,
    Hammer,
    Spanner = 78,
    GhostKnife = 80,
    Firebomb,
    Diversion,
    FragGrenade,
    Snowball,
    BumpMine,
    Bayonet = 500,
    Flip = 505,
    Gut,
    Karambit,
    M9Bayonet,
    Huntsman,
    Falchion = 512,
    Bowie = 514,
    Butterfly,
    Daggers,
    Ursus = 519,
    Navaja,
    Stiletto = 522,
    Talon,
    GloveStuddedBloodhound = 5027,
    GloveT,
    GloveCT,
    GloveSporty,
    GloveSlick,
    GloveLeatherWrap,
    GloveMotorcycle,
    GloveSpecialist,
    GloveHydra
};

constexpr int getWeaponIndex(WeaponId weaponId) noexcept
{
    switch (weaponId) {
    default: return 0;

    case WeaponId::Glock: return 1;
    case WeaponId::Hkp2000: return 2;
    case WeaponId::Usp_s: return 3;
    case WeaponId::Elite: return 4;
    case WeaponId::P250: return 5;
    case WeaponId::Tec9: return 6;
    case WeaponId::Fiveseven: return 7;
    case WeaponId::Cz75a: return 8;
    case WeaponId::Deagle: return 9;
    case WeaponId::Revolver: return 10;

    case WeaponId::Nova: return 11;
    case WeaponId::Xm1014: return 12;
    case WeaponId::Sawedoff: return 13;
    case WeaponId::Mag7: return 14;
    case WeaponId::M249: return 15;
    case WeaponId::Negev: return 16;

    case WeaponId::Mac10: return 17;
    case WeaponId::Mp9: return 18;
    case WeaponId::Mp7: return 19;
    case WeaponId::Mp5sd: return 20;
    case WeaponId::Ump45: return 21;
    case WeaponId::P90: return 22;
    case WeaponId::Bizon: return 23;

    case WeaponId::GalilAr: return 24;
    case WeaponId::Famas: return 25;
    case WeaponId::Ak47: return 26;
    case WeaponId::M4A1: return 27;
    case WeaponId::M4a1_s: return 28;
    case WeaponId::Ssg08: return 29;
    case WeaponId::Sg553: return 30;
    case WeaponId::Aug: return 31;
    case WeaponId::Awp: return 32;
    case WeaponId::G3SG1: return 33;
    case WeaponId::Scar20: return 34;

    case WeaponId::Taser: return 39;

    case WeaponId::Flash: return 41;
    case WeaponId::Decoy: return 42;
    case WeaponId::HEGrenade: return 43;
    case WeaponId::IncGrenade: return 44;
    case WeaponId::Molotov: return 45;
    case WeaponId::SmokeGrenade: return 46;
    }
}

constexpr int getWeaponClass(WeaponId weaponId) noexcept
{
    switch (weaponId) {
    default: return 0;

    case WeaponId::Glock:
    case WeaponId::Hkp2000:
    case WeaponId::Usp_s:
    case WeaponId::Elite:
    case WeaponId::P250:
    case WeaponId::Tec9:
    case WeaponId::Fiveseven:
    case WeaponId::Cz75a:
    case WeaponId::Deagle:
    case WeaponId::Revolver: return 35;

    case WeaponId::Nova:
    case WeaponId::Xm1014:
    case WeaponId::Sawedoff:
    case WeaponId::Mag7:
    case WeaponId::M249:
    case WeaponId::Negev: return 36;

    case WeaponId::Mac10:
    case WeaponId::Mp9:
    case WeaponId::Mp7:
    case WeaponId::Mp5sd:
    case WeaponId::Ump45:
    case WeaponId::P90:
    case WeaponId::Bizon: return 37;

    case WeaponId::GalilAr:
    case WeaponId::Famas:
    case WeaponId::Ak47:
    case WeaponId::M4A1:
    case WeaponId::M4a1_s:
    case WeaponId::Ssg08:
    case WeaponId::Sg553:
    case WeaponId::Aug:
    case WeaponId::Awp:
    case WeaponId::G3SG1:
    case WeaponId::Scar20: return 38;

    case WeaponId::Flash:
    case WeaponId::Decoy:
    case WeaponId::HEGrenade:
    case WeaponId::IncGrenade:
    case WeaponId::Molotov:
    case WeaponId::SmokeGrenade: return 40;
    }
}
