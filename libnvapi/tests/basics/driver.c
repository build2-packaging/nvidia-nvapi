#include <stdio.h>

#include <nvapi.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  NvAPI_Status s = NvAPI_Initialize ();

  if (s != NVAPI_OK)
  {
    printf ("NvAPI_Initialize: %d, skipping GPU info\n", (int) s);
    return 0;
  }

  {
    NvU32 version = 0;
    NvAPI_ShortString branch;

    assert (NvAPI_SYS_GetDriverAndBranchVersion (&version, branch) == NVAPI_OK);
    printf ("libnvapi - NvAPI_SYS_GetDriverAndBranchVersion(): v%u.%u (%u) %s\n",
            (unsigned) version / 100,
            (unsigned) version % 100,
            (unsigned) version,
            branch);
  }

  assert (NvAPI_Unload () == NVAPI_OK);
  return 0;
}
