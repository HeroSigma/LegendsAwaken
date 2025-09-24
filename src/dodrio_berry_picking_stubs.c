// Weak stubs to satisfy linkage if Dodrio Berry Picking is excluded by build order.
#include "global.h"
#include "dodrio_berry_picking.h"
#include "event_data.h" // for gSpecialVar_Result

__attribute__((weak)) void StartDodrioBerryPicking(u16 partyId, void (*exitCallback)(void))
{
    (void)partyId; (void)exitCallback;
}

__attribute__((weak)) void IsDodrioInParty(void)
{
    gSpecialVar_Result = FALSE;
}

__attribute__((weak)) void ShowDodrioBerryPickingRecords(void)
{
}
