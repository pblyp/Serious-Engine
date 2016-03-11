/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 4 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"

#include "StdH.h"
#include "EntitiesMP/MusicHolder.h"

#include <EntitiesMP/PlayerMarker.h>
#include <EntitiesMP/PlayerMarker_tables.h>
#line 11 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"

  extern void CPlayerWeapons_Precache(ULONG ulAvailable);

void CPlayerMarker::SetDefaultProperties(void) {
  m_fHealth = 100.0f;
  m_fShield = 0.0f;
  m_iGiveWeapons = 0x1;
  m_iTakeWeapons = 0x0;
  m_strGroup = "";
  m_bQuickStart = FALSE ;
  m_bStartInComputer = FALSE ;
  m_penMessage = NULL;
  m_fMaxAmmoRatio = 0.0f;
  m_tmLastSpawned = -1000.0f;
  m_iTakeAmmo = 0x0;
  m_bNoRespawnInPlace = FALSE ;
  CMarker::SetDefaultProperties();
}
  
#line 39 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
void CPlayerMarker::Precache(void) {
#line 40 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(m_iGiveWeapons  > 1){
#line 41 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
CPlayerWeapons_Precache  (m_iGiveWeapons );
#line 42 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 43 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
  
#line 44 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
BOOL CPlayerMarker::HandleEvent(const CEntityEvent & ee) {
#line 45 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger ){
#line 46 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
CEntity  * penMainMusicHolder  = _pNetwork  -> GetEntityWithName  ("MusicHolder" , 0);
#line 47 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(penMainMusicHolder  == NULL  || ! IsOfClass  (penMainMusicHolder  , "MusicHolder")){
#line 48 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
return TRUE ;
#line 49 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 50 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
CMusicHolder  * pmh  = (CMusicHolder  *) penMainMusicHolder ;
#line 51 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
BOOL bNew  = (pmh  -> m_penRespawnMarker  != this );
#line 52 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
pmh  -> m_penRespawnMarker  = this ;
#line 55 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
CEntity  * penCaused  = ((ETrigger  &) ee ) . penCaused ;
#line 56 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(bNew  && 
#line 57 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
(GetSP  () -> sp_bSinglePlayer  && GetSP  () -> sp_gmGameMode  != CSessionProperties  :: GM_FLYOVER ) 
#line 58 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
&& IsOfClass  (penCaused  , "Player")){
#line 60 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
CPlayerSettings  * pps  = (CPlayerSettings  *) (((CPlayerEntity  *) penCaused ) -> en_pcCharacter  . pc_aubAppearance );
#line 61 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(pps  -> ps_ulFlags  & PSF_AUTOSAVE ){
#line 63 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
_pShell  -> Execute  ("gam_bQuickSave=1;");
#line 64 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 65 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 66 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
return TRUE ;
#line 67 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 69 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
return FALSE ;
#line 70 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
BOOL CPlayerMarker::
#line 73 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPlayerMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 75 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
InitAsEditorModel  ();
#line 76 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 77 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 80 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
SetModel  (MODEL_MARKER );
#line 81 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 84 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
if(m_bQuickStart ){
#line 85 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
m_strName  . PrintF  ("Player Quick Start");
#line 86 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}else {
#line 87 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
m_strName  . PrintF  ("Player Start - %s" , m_strGroup );
#line 88 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
}
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
Return(STATE_CURRENT,EVoid());
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/PlayerMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};