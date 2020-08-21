#pragma once
#include <cstdint>
#include <vector>


uintptr_t FindAddressByOffset(uintptr_t baseaddr, std::vector<uintptr_t>& offsets)
{
	uintptr_t final_address = baseaddr;
	for (auto el : offsets)
	{

		final_address = *reinterpret_cast<uintptr_t*>(final_address);
		final_address += el;
	
	}
	return final_address;
}


// Created with ReClass.NET 1.2 by KN4CK3R
class Vector3
{
public:
	float x;
	float y;
	float z;



};



// Created with ReClass.NET 1.2 by KN4CK3R

enum class TeamIndex : int64_t
{
	
	Count = 3,
	Monster = 2,
	Neutral = 0,
	None = -1,
	Player = 1
};

class CharacterMaster
{
public:
	char pad_0000[80]; //0x0000
	void* inventory; //0x0050
	char pad_0058[8]; //0x0058
	class PlayerCharacterMasterController* playercharactermastercontroller; //0x0060
	void* PlayerStatsComponent; //0x0068
	char pad_0070[8]; //0x0070
	class Loadout* loadout; //0x0078
	char pad_0080[20]; //0x0080
	bool SpawnOnStart; //0x0094
	int8_t TeamIndex; //0x0095
	char pad_0096[6]; //0x0096
	bool bodyResolved; //0x009C
	char pad_009D[3]; //0x009D
	uint32_t _money; //0x00A0
	float luck; //0x00A4
	bool isBoss; //0x00A8
	bool preventGameOver; //0x00A9
	char pad_00AA[2]; //0x00AA
	Vector3 deathFootPosition; //0x00AC
	Vector3 DeathAimVector; //0x00B8
	float _internalSurvivalTime; //0x00C4
	int32_t killerBodyIndex; //0x00C8
	bool preventRespawnUntilNextStageServer; //0x00CC
	bool godMode; //0x00CD
	uint32_t lostBodyToDeathFlag; //0x00CE
	char pad_00D2[2]; //0x00D2
	int32_t _miscFlags; //0x00D4
	char pad_00D8[209]; //0x00D8
}; //Size: 0x01A9

class PlayerCharacterMasterController
{
public:
	char pad_0000[32]; //0x0000
	int32_t m_SyncVarDirtyBits; //0x0020
	float m_LastSendTime; //0x0024
	char pad_0028[8]; //0x0028
	void* body; //0x0030
	void* bodyInputs; //0x0038
	void* bodyMotor; //0x0040
	void* master; //0x0048
	void* finalmessagetokenserver; //0x0050
	void* pingerController; //0x0058
	void* resolvedNetworkUserGameObjectInstance; //0x0060
	void* resolvedNetworkUserInstance; //0x0068
	char pad_0070[8]; //0x0070
	void* netid; //0x0078
	int32_t networkUserInstanceId; //0x0080
	bool networkUserResolved; //0x0084
	char pad_0085[3]; //0x0085
	float cameraMinPitch; //0x0088
	float cameraMaxPitch; //0x008C
	Vector3 crosshairPosition; //0x0090
	bool sprintInputPressReceived; //0x009C
	char pad_009D[3]; //0x009D
	float lunarCoinChanceMultiplier; //0x00A0
	char pad_00A4[35]; //0x00A4
}; //Size: 0x00C7

class Loadout
{
public:
	char pad_0000[16]; //0x0000
	void* bodyLoadoutManager; //0x0010
	char pad_0018[40]; //0x0018
}; //Size: 0x0040

class BodyLoadoutManager
{
public:
	char pad_0000[16]; //0x0000
	class BodyLoadout* modifiedBodyLoadouts; //0x0010
	char pad_0018[40]; //0x0018
}; //Size: 0x0040

class N00000231
{
public:
	void* bodyloadout; //0x0000
	char pad_0008[56]; //0x0008
}; //Size: 0x0040

class BodyLoadout
{
public:
	char pad_0000[16]; //0x0000
	char(*skillPreferences)[15][8]; //0x0010
	int32_t bodyindex; //0x0018
	int32_t skinPreference; //0x001C
	char pad_0020[32]; //0x0020
}; //Size: 0x0040

class HealthComponent
{
public:
	char pad_0000[16]; //0x0000
	void* m_CachedPtr; //0x0010
	char pad_0018[80]; //0x0018
	float health; //0x0068
	float shield; //0x006C
	float barrier; //0x0070
	float magnetiCharge; //0x0074
	bool dontShowHealthbar; //0x0078
	char pad_0079[3]; //0x0079
	float globalDeathEventChanceCoefficient; //0x007C
	char pad_0080[12]; //0x0080
	bool godMode; //0x008C
	char pad_008D[7]; //0x008D
	bool isInFrozenState; //0x0094
	char pad_0095[15]; //0x0095
	bool wasAlive; //0x00A4
	char pad_00A5[3]; //0x00A5
	float adaptiveArmorValue; //0x00A8
	char pad_00AC[217]; //0x00AC
}; //Size: 0x0185

class N000003E2
{
public:
	char pad_0000[40]; //0x0000
	class HealthComponent* hc; //0x0028
	char pad_0030[16]; //0x0030
}; //Size: 0x0040

class CameraRigController
{
public:
	char pad_0000[24]; //0x0000
	void* scenecam; //0x0018
	void* uicam; //0x0020
	void* skyboxcam; //0x0028
	void* sprintingParticleSystem; //0x0030
	void* overrideCam; //0x0038
	void* _viewer; //0x0040
	void* _localUserViewer; //0x0048
	void* hud; //0x0050
	void* previousTarget; //0x0058
	void* target; //0x0060
	void* targetBody; //0x0068
	void* firstPersonTarget; //0x0070
	void* targetParams; //0x0078
	class AimAssistInfo* lastAimAssist; //0x0080
	char pad_0088[24]; //0x0088
	class AimAssistInfo* aimAssist; //0x00A0
	char pad_00A8[24]; //0x00A8
	class HurtBox* lastCrosshairHurtBox; //0x00C0
	float baseFov; //0x00C8
	float currentFov; //0x00CC
	float fovVelocity; //0x00D0
	bool enableFading; //0x00D4
	char pad_00D5[3]; //0x00D5
	float fadeStartDistance; //0x00D8
	float fadeEndDistance; //0x00DC
	bool disableSpectating; //0x00E0
	char pad_00E1[3]; //0x00E1
	float maxAimRaycastDistance; //0x00E4
	char pad_00E8[146]; //0x00E8
	int8_t targetTeamIndex; //0x017A
	char pad_017B[1]; //0x017B
	float pitch; //0x017C
	float yaw; //0x0180
	Vector3 crosshairWorldPosition; //0x0184
	float currentCameraDistance; //0x0190
	float cameraDistanceVelocity; //0x0194
	char pad_0198[48]; //0x0198
	float hitmarkerAlpha; //0x01C8
	float hitmarkerTimer; //0x01CC
	char pad_01D0[564]; //0x01D0
}; //Size: 0x0404

class AimAssistInfo
{
public:
	char pad_0000[16]; //0x0000
	void* aimAssistHurtbox; //0x0010
	Vector3 localPositionOnHurtbox; //0x0018
	Vector3 worldPosition; //0x0024
	char pad_0030[24]; //0x0030
}; //Size: 0x0048

class HurtBox
{
public:
	char pad_0000[24]; //0x0000
	class HealthComponent* healthComponent; //0x0018
	void* hurtBoxGroup; //0x0020
	void* collider; //0x0028
	bool isBullseye; //0x0030
	char pad_0031[3]; //0x0031
	int32_t damageModifier; //0x0034
	int8_t teamIndex; //0x0038
	int16_t indexInGroup; //0x0039
	char pad_003B[1]; //0x003B
	float volume; //0x003C
	char pad_0040[4]; //0x0040
}; //Size: 0x0044

class CharacterBody
{
public:
	
	char pad_0000[112]; //0x0000
	void* inventory; //0x0070
	char pad_0078[56]; //0x0078
	class HealthComponent* healthComponent; //0x00B0
	char pad_00B8[376]; //0x00B8
	int32_t bodyIndex; //0x0230
	int32_t activeBuffsListCount; //0x0234
	int32_t eliteBuffCount; //0x0238
	int32_t pendingTonicAfflictionCount; //0x023C
	int32_t bodyFlags; //0x0240
	int32_t masterObjectId; //0x0244
	bool linkedToMaster; //0x0248
	bool isPlayerControlled; //0x0249
	bool disablingHurtBoxes; //0x024A
	char pad_024B[1]; //0x024B
	int32_t previousEquipmentIndex; //0x024C
	char pad_0250[4]; //0x0250
	bool hasEffectiveAuthority; //0x0254
	bool _isSprinting; //0x0255
	char pad_0256[2]; //0x0256
	float outOfCombatStopwatch; //0x0258
	float outOfDangerStopwatch; //0x025C
	bool outOfCombat; //0x0260
	bool _outOfDanger; //0x0261
	char pad_0262[2]; //0x0262
	Vector3 previousPosition; //0x0264
	float notMovingStopwatch; //0x0270
	bool rootMotionInMainState; //0x0274
	char pad_0275[3]; //0x0275
	float mainRootSpeed; //0x0278
	float baseMaxHealth; //0x027C
	float baseRegen; //0x0280
	float baseMaxShield; //0x0284
	float baseMoveSpeed; //0x0288
	float baseAcceleration; //0x028C
	float baseJumpPower; //0x0290
	float baseDamage; //0x0294
	float baseAttackSpeed; //0x0298
	float baseCrit; //0x029C
	float baseArmor; //0x02A0
	float baseJumpCount; //0x02A4
	float sprintingSpeedMultiplier; //0x02A8
	float autoCalculateLevelStats; //0x02AC
	float levelMaxHealth; //0x02B0
	float levelRegen; //0x02B4
	float levelMaxShield; //0x02B8
	float levelMoveSpeed; //0x02BC
	float levelJumpPower; //0x02C0
	float levelDamage; //0x02C4
	float levelAttackSpeed; //0x02C8
	float levelCrit; //0x02CC
	float levelArmor; //0x02D0
	float experience; //0x02D4
	float level; //0x02D8
	float maxhealth; //0x02DC
	float maxBarrier; //0x02E0
	float barrierDecayRate; //0x02E4
	float regen; //0x02E8
	float maxShield; //0x02EC
	float moveSpeed; //0x02F0
	float acceleration; //0x02F4
	float jumpPower; //0x02F8
	int32_t maxJumpCoun; //0x02FC
	float maxJumpHeight; //0x0300
	float damage; //0x0304
	float attackSpeed; //0x0308
	float crit; //0x030C
	float armor; //0x0310
	float critHeal; //0x0314
	float cursePenalty; //0x0318
	bool hasOneShotProtection; //0x031C
	bool isGlass; //0x031D
	char pad_031E[2]; //0x031E
	float oneShotProtectionFraction; //0x0320
	bool statsDirty; //0x0324
	char pad_0325[3]; //0x0325
	float aimTimer; //0x0328
	float warCryTimer; //0x032C
	bool _warCryReady; //0x0330
	char pad_0331[3]; //0x0331
	int32_t killCount; //0x0334
	float teslaBuffRollTimer; //0x0338
	float teslaFireTimer; //0x033C
	float teslaResetListTimer; //0x0340
	float teslaResetListInterval; //0x0344
	bool teslaCrit; //0x0348
	char pad_0349[3]; //0x0349
	float helfireLifetime; //0x034C
	bool wasLucky; //0x0350
	char pad_0351[3]; //0x0351
	bool guardResummonCooldown; //0x0354
	char pad_0355[3]; //0x0355
	float poisonballTimer; //0x0358
	float wardResummonCooldown; //0x035C
	float spreadBloomDecayTime; //0x0360
	float spreadBloomInternal; //0x0364
	bool hideCrosshair; //0x0368
	char pad_0369[3]; //0x0369
	float multiKillTimer; //0x036C
	int32_t multiKillCount; //0x0370
	float radius; //0x0374
	char pad_0378[4]; //0x0378
	bool isChampion; //0x037C
	bool isElite; //0x037D
	char pad_037E[2]; //0x037E
	int32_t skinIndex; //0x0380
	int32_t localStartTime; //0x0384
}; //Size: 0x0388