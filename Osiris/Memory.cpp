#include "Interfaces.h"
#include "Memory.h"
#include "SDK/LocalPlayer.h"

template <typename T>
static constexpr auto relativeToAbsolute(int* address) noexcept
{
    return reinterpret_cast<T>(reinterpret_cast<char*>(address + 1) + *address);
}


Memory::Memory() noexcept
{
    present = findPattern(L"gameoverlayrenderer", "\xFF\x15????\x8B\xF8\x85\xDB") + 2;
    reset = findPattern(L"gameoverlayrenderer", "\xC7\x45?????\xFF\x15????\x8B\xF8") + 9;
    clientMode = **reinterpret_cast<ClientMode***>((*reinterpret_cast<uintptr_t**>(interfaces->client))[10] + 5);
    input = *reinterpret_cast<Input**>((*reinterpret_cast<uintptr_t**>(interfaces->client))[16] + 1);
    globalVars = **reinterpret_cast<GlobalVars***>((*reinterpret_cast<uintptr_t**>(interfaces->client))[11] + 10);  
    glowObjectManager = *reinterpret_cast<GlowObjectManager**>(findPattern(L"client", "\x0F\x11\x05????\x83\xC8\x01") + 3);
    disablePostProcessing = *reinterpret_cast<bool**>(findPattern(L"client", "\x83\xEC\x4C\x80\x3D") + 5);
    loadSky = relativeToAbsolute<decltype(loadSky)>(reinterpret_cast<int*>(findPattern(L"engine", "\xE8????\x84\xC0\x74\x2D\xA1") + 1));
    setClanTag = reinterpret_cast<decltype(setClanTag)>(findPattern(L"engine", "\x53\x56\x57\x8B\xDA\x8B\xF9\xFF\x15"));
    lineGoesThroughSmoke = relativeToAbsolute<decltype(lineGoesThroughSmoke)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x8B\x4C\x24\x30\x33\xD2") + 1));
    smokeCount = *(reinterpret_cast<int**>(lineGoesThroughSmoke) + 2);
    cameraThink = findPattern(L"client", "\x85\xC0\x75\x30\x38\x86");
    acceptMatch = reinterpret_cast<decltype(acceptMatch)>(findPattern(L"client", "\x55\x8B\xEC\x83\xE4\xF8\x8B\x4D\x08\xBA????\xE8????\x85\xC0\x75\x12"));
    getSequenceActivity = reinterpret_cast<decltype(getSequenceActivity)>(findPattern(L"client", "\x55\x8B\xEC\x53\x8B\x5D\x08\x56\x8B\xF1\x83"));
    scopeArc = findPattern(L"client", "\x6A?\xFF\x50\x3C\x8B\x0D????\xFF\xB7") + 5;
    scopeLens = findPattern(L"client", "\xFF\x50\x3C\x8B\x4C\x24\x20") + 3;
    isOtherEnemy = relativeToAbsolute<decltype(isOtherEnemy)>(reinterpret_cast<int*>(findPattern(L"client", "\x8B\xCE\xE8????\x02\xC0") + 3));
    auto temp = reinterpret_cast<std::uintptr_t*>(findPattern(L"client", "\xB9????\xE8????\x8B\x5D\x08") + 1);
    hud = *temp;
    findHudElement = relativeToAbsolute<decltype(findHudElement)>(reinterpret_cast<int*>(reinterpret_cast<char*>(temp) + 5));
    clearHudWeapon = reinterpret_cast<decltype(clearHudWeapon)>(findPattern(L"client", "\x55\x8B\xEC\x51\x53\x56\x8B\x75\x08\x8B\xD9\x57\x6B\xFE\x2C"));
    itemSystem = relativeToAbsolute<decltype(itemSystem)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x0F\xB7\x0F") + 1));
    setAbsOrigin = relativeToAbsolute<decltype(setAbsOrigin)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\xEB\x19\x8B\x07") + 1));
    listLeaves = findPattern(L"client", "\x56\x52\xFF\x50\x18") + 5;
    dispatchSound = reinterpret_cast<int*>(findPattern(L"engine", "\x74\x0B\xE8????\x8B\x3D") + 3);
    traceToExit = reinterpret_cast<decltype(traceToExit)>(findPattern(L"client", "\x55\x8B\xEC\x83\xEC\x30\xF3\x0F\x10\x75"));
    viewRender = **reinterpret_cast<ViewRender***>(findPattern(L"client", "\x8B\x0D????\xFF\x75\x0C\x8B\x45\x08") + 2);
    drawScreenEffectMaterial = relativeToAbsolute<uintptr_t>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x83\xC4\x0C\x8D\x4D\xF8") + 1));
    submitReport = reinterpret_cast<decltype(submitReport)>(findPattern(L"client", "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x28\x8B\x4D\x08"));
    fakePrime = reinterpret_cast<std::uint8_t*>(findPattern(L"client", "\x17\xF6\x40\x14\x10") - 1);
    const auto tier0 = GetModuleHandleW(L"tier0");
    debugMsg = reinterpret_cast<decltype(debugMsg)>(GetProcAddress(tier0, "Msg"));
    conColorMsg = reinterpret_cast<decltype(conColorMsg)>(GetProcAddress(tier0, "?ConColorMsg@@YAXABVColor@@PBDZZ"));
    vignette = *reinterpret_cast<float**>(findPattern(L"client", "\x0F\x11\x05????\xF3\x0F\x7E\x87") + 3) + 1;
    equipWearable = reinterpret_cast<decltype(equipWearable)>(findPattern(L"client", "\x55\x8B\xEC\x83\xEC\x10\x53\x8B\x5D\x08\x57\x8B\xF9"));
    predictionRandomSeed = *reinterpret_cast<int**>(findPattern(L"client", "\x8B\x0D????\xBA????\xE8????\x83\xC4\x04") + 2);
    moveData = **reinterpret_cast<MoveData***>(findPattern(L"client", "\xA1????\xF3\x0F\x59\xCD") + 1);
    moveHelper = **reinterpret_cast<MoveHelper***>(findPattern(L"client", "\x8B\x0D????\x8B\x45?\x51\x8B\xD4\x89\x02\x8B\x01") + 2);
    keyValuesFromString = relativeToAbsolute<decltype(keyValuesFromString)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x83\xC4\x04\x89\x45\xD8") + 1));
    keyValuesFindKey = relativeToAbsolute<decltype(keyValuesFindKey)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\xF7\x45") + 1));
    keyValuesSetString = relativeToAbsolute<decltype(keyValuesSetString)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x89\x77\x38") + 1));
    weaponSystem = *reinterpret_cast<WeaponSystem**>(findPattern(L"client", "\x8B\x35????\xFF\x10\x0F\xB7\xC0") + 2);
    getPlayerViewmodelArmConfigForPlayerModel = relativeToAbsolute<decltype(getPlayerViewmodelArmConfigForPlayerModel)>(reinterpret_cast<int*>(findPattern(L"client", "\xE8????\x89\x87????\x6A\x00") + 1));
    getEventDescriptor = relativeToAbsolute<decltype(getEventDescriptor)>(reinterpret_cast<int*>(findPattern(L"engine", "\xE8????\x8B\xD8\x85\xDB\x75\x27") + 1));
    setAbsAngle = reinterpret_cast<decltype(setAbsAngle)>(reinterpret_cast<DWORD*>(findPattern(L"client", "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x64\x53\x56\x57\x8B\xF1")));
    CreateState = findPattern(L"client", "\x55\x8B\xEC\x56\x8B\xF1\xB9????\xC7\x46");
    UpdateState = findPattern(L"client", "\x55\x8B\xEC\x83\xE4\xF8\x83\xEC\x18\x56\x57\x8B\xF9\xF3\x0F\x11\x54\x24");
    InvalidateBoneCache = findPattern(L"client", "\x80\x3D?????\x74\x16\xA1????\x48\xC7\x81");
    memalloc = *reinterpret_cast<MemAlloc**>(GetProcAddress(GetModuleHandleA("tier0.dll"), "g_pMemAlloc"));
    renderBeams = *reinterpret_cast<IViewRenderBeams**>(findPattern(L"client", "\xB9????\xA1????\xFF\x10\xA1????\xB9" + 1));
    activeChannels = *reinterpret_cast<ActiveChannels**>(findPattern(L"engine", "\x8B\x1D????\x89\x5C\x24\x48") + 2);
    channels = *reinterpret_cast<Channel**>(findPattern(L"engine", "\x81\xC2????\x8B\x72\x54") + 2);
    localPlayer.init(*reinterpret_cast<Entity***>(findPattern(L"client", "\xA1????\x89\x45\xBC\x85\xC0") + 1));
}
