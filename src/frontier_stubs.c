#if FREE_BATTLE_FRONTIER == TRUE
#include "global.h"
#include "event_data.h"
#include "constants/battle_string_ids.h"
#include "battle_arena.h"
#include "battle_factory.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "battle_tower.h"
#include "battle_tent.h"
#include "frontier_pass.h"
#include "data.h"
#include "main.h"

// No-op Frontier entry points and helpers
void CallFrontierUtilFunc(void) {}
void CallBattleTowerFunc(void) {}
void CallBattleDomeFunction(void) {}
void CallBattlePalaceFunction(void) {}
void CallBattleArenaFunction(void) {}
void CallBattleFactoryFunction(void) {}
void CallBattlePikeFunction(void) {}
void CallBattlePyramidFunction(void) {}
void CallVerdanturfTentFunction(void) {}
void CallFallarborTentFunction(void) {}
void CallSlateportTentFunction(void) {}

// Tower helpers / data
enum TrainerClassID GetFrontierOpponentClass(u16 trainerId) { (void)trainerId; return 0; }
void FillFrontierTrainersParties(u8 monsCount) { (void)monsCount; }
bool32 RubyBattleTowerRecordToEmerald(struct RSBattleTowerRecord *src, struct EmeraldBattleTowerRecord *dst) { (void)src; (void)dst; return FALSE; }
bool32 EmeraldBattleTowerRecordToRuby(struct EmeraldBattleTowerRecord *src, struct RSBattleTowerRecord *dst) { (void)src; (void)dst; return FALSE; }
enum TrainerClassID GetEreaderTrainerClassId(void) { return 0; }
void GetEreaderTrainerName(u8 *dst) { if (dst) dst[0] = 0; }
void CopyEReaderTrainerGreeting(void) {}
void DoSpecialTrainerBattle(void) {}
void TryHideBattleTowerReporter(void) {}
void ValidateEReaderTrainer(void) {}
void SetEReaderTrainerGfxId(void) {}
u8 GetFrontierTrainerFrontSpriteId(u16 trainerId) { (void)trainerId; return 0; }
void GetFrontierTrainerName(u8 *dst, u16 trainerId) { (void)trainerId; if (dst) dst[0] = 0; }
void FillFrontierTrainerParty(u8 monsCount) { (void)monsCount; }
void GetBattleTowerTrainerLanguage(u8 *dst, u16 trainerId) { (void)trainerId; if (dst) *dst = GAME_LANGUAGE; }
void FrontierSpeechToString(const u16 *words) { (void)words; }
u8 GetEreaderTrainerFrontSpriteId(void) { return 0; }
void TrySetLinkBattleTowerEnemyPartyLevel(void) {}
u16 GetCurrentBattleTowerWinStreak(u8 lvlMode, u8 battleMode) { (void)lvlMode; (void)battleMode; return 0; }
void CalcApprenticeChecksum(struct Apprentice *apprentice) { (void)apprentice; }
void PutNewBattleTowerRecord(struct EmeraldBattleTowerRecord *newRecordEm) { (void)newRecordEm; }

// Factory/AI
u64 GetAiScriptsInBattleFactory(void) { return 0; }
bool8 InBattleFactory(void) { return FALSE; }

// Arena
void BattleArena_DeductSkillPoints(u8 battler, enum StringID stringId) { (void)battler; (void)stringId; }
u8 BattleArena_ShowJudgmentWindow(u8 *state) { if (state) *state = 0; return 0; }
void BattleArena_InitPoints(void) {}
void BattleArena_AddSkillPoints(u8 battler) { (void) battler; }
void BattleArena_AddMindPoints(u8 battler) { (void) battler; }
void DrawArenaRefereeTextBox(void) {}
void EraseArenaRefereeTextBox(void) {}

// Pike / Pyramid environment
bool8 InBattlePyramid_(void) { return FALSE; }
u8 GetBattlePikeWildMonHeaderId(void) { return 0; }
bool32 TryGenerateBattlePikeWildMon(bool8 checkKeenEyeIntimidate) { (void)checkKeenEyeIntimidate; return FALSE; }
bool8 InBattlePike(void) { return FALSE; }
bool8 GetBattlePyramidTrainerFlag(u8 eventId) { (void)eventId; return FALSE; }
void MarkApproachingPyramidTrainersAsBattled(void) {}
void GenerateBattlePyramidWildMon(void) {}
u8 CurrentBattlePyramidLocation(void) { return 0; }
void PausePyramidChallenge(void) {}
void SoftResetInBattlePyramid(void) {}
u16 GetBattlePyramidPickupItemId(void) { return 0; }
u8 GetPyramidRunMultiplier(void) { return 0; }
u8 GetNumBattlePyramidObjectEvents(void) { return 0; }
void GenerateBattlePyramidFloorLayout(u16 *backupMapData, bool8 setPlayerPosition) { (void)backupMapData; (void)setPlayerPosition; }
void LoadBattlePyramidObjectEventTemplates(void) {}
void LoadBattlePyramidFloorObjectEventScripts(void) {}
u16 LocalIdToPyramidTrainerId(u8 localId) { (void)localId; return 0; }
void CopyPyramidTrainerSpeechBefore(u16 trainerId) { (void)trainerId; }
void CopyPyramidTrainerWinSpeech(u16 trainerId) { (void)trainerId; }
void CopyPyramidTrainerLoseSpeech(u16 trainerId) { (void)trainerId; }
u8 GetTrainerEncounterMusicIdInBattlePyramid(u16 trainerId) { (void)trainerId; return 0; }

// Pyramid bag helpers
struct PyramidBagMenu *gPyramidBagMenu = NULL;
struct PyramidBagMenuState gPyramidBagMenuState = {0};
void TryStoreHeldItemsInPyramidBag(void) {}
void ChooseItemsToTossFromPyramidBag(void) {}
void CB2_PyramidBagMenuFromStartMenu(void) {}
void DisplayItemMessageInBattlePyramid(u8 taskId, const u8 *str, void (*callback)(u8 taskId)) { (void)taskId; (void)str; (void)callback; }
void Task_CloseBattlePyramidBagMessage(u8 taskId) { (void)taskId; }
void CloseBattlePyramidBag(u8 taskId) { (void)taskId; }
void UpdatePyramidBagList(void) {}
void UpdatePyramidBagCursorPos(void) {}
void GoToBattlePyramidBagMenu(u8 location, void (*exitCallback)(void)) { (void)location; (void)exitCallback; }
void CB2_ReturnToPyramidBagMenu(void) {}

// Frontier Pass
void ShowFrontierPass(void (*callback)(void)) { if (callback) callback(); }
void CB2_ReshowFrontierPass(void) { if (gMain.savedCallback) SetMainCallback2(gMain.savedCallback); }

// Transition tasks from frontier transition module
void Task_FrontierCirclesMeet(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesCross(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesAsymmetricSpiral(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesSymmetricSpiral(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesMeetInSeq(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesCrossInSeq(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesAsymmetricSpiralInSeq(u8 taskId) { (void)taskId; }
void Task_FrontierCirclesSymmetricSpiralInSeq(u8 taskId) { (void)taskId; }

// Partner trainer data (dummy)
const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT] = {0};

// Tower facility class/GFX lookup tables (dummy)
const u8 gTowerMaleFacilityClasses[30] = {0};
const u16 gTowerMaleTrainerGfxIds[30] = {0};
const u8 gTowerFemaleFacilityClasses[20] = {0};
const u16 gTowerFemaleTrainerGfxIds[20] = {0};

// Tent
bool8 InSlateportBattleTent(void) { return FALSE; }

// Frontier Brain / Util stubs
u8 GetFrontierBrainStatus(void) { return 0; }
void CopyFrontierTrainerText(u8 whichText, u16 trainerId) { (void)whichText; (void)trainerId; }
u32 GetCurrentFacilityWinStreak(void) { return 0; }
void ResetWinStreaks(void) {}
void ResetFrontierTrainerIds(void) {}
u8 GetPlayerSymbolCountForFacility(u8 facility) { (void)facility; return 0; }
void ShowRankingHallRecordsWindow(void) {}
void ScrollRankingHallRecordsWindow(void) {}
void ClearRankingHallRecords(void) {}
void SaveGameFrontier(void) {}
u8 GetFrontierBrainTrainerPicIndex(void) { return 0; }
enum TrainerClassID GetFrontierBrainTrainerClass(void) { return 0; }
void CopyFrontierBrainTrainerName(u8 *dst) { if (dst) dst[0] = 0; }
bool8 IsFrontierBrainFemale(void) { return FALSE; }
void SetFrontierBrainObjEventGfx_2(void) {}
void CreateFrontierBrainPokemon(void) {}
u16 GetFrontierBrainMonSpecies(u8 monId) { (void)monId; return 0; }
void SetFrontierBrainObjEventGfx(u8 facility) { (void)facility; }
u16 GetFrontierBrainMonMove(u8 monId, u8 moveSlotId) { (void)monId; (void)moveSlotId; return 0; }
u8 GetFrontierBrainMonNature(u8 monId) { (void)monId; return 0; }
u8 GetFrontierBrainMonEvs(u8 monId, u8 evStatId) { (void)monId; (void)evStatId; return 0; }
s32 GetFronterBrainSymbol(void) { return 0; }
void ClearEnemyPartyAfterChallenge(void) {}

// Additional Tower/util helpers needed by non-Frontier code paths
void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *record) { (void)record; }
u8 GetFrontierEnemyMonLevel(u8 lvlMode) { (void)lvlMode; return 0; }
s32 GetHighestLevelInPlayerParty(void) { return 0; }
u16 FacilityClassToGraphicsId(u8 facilityClass) { (void)facilityClass; return 0; }

#endif // FREE_BATTLE_FRONTIER
