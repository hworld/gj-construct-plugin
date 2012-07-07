// Main.h
// Definitions and classes for the object workings

// Only include once
#ifndef MAIN_H
#define MAIN_H

#define MINIMUM_VERSION	1

// IDE FLAGS
// Can be a combination of:
//OF_NOSIZE	- Extension cannot be resized at edittime
//OF_NODRAW - Extension does not display anything
//OF_ALLOWANGLES - Can be rotated at edittime
//OF_PRIVATEVARIABLES - Uses private variables
//OF_MOVEMENTPLUGIN - Is a movement plugin
//OF_MOVEMENTS - Allow movement plugins to be added
//OF_EFFECTS - Allow display effects
//OF_NOCOMMONDEBUG - Don't show 'Common' field (X/Y/W/H/Angle/Opacity) in debugger
//OF_NODEBUG - Don't show at all in debugger
//OF_UNDEFINEDEXPRESSIONS - Allow ReturnUndefinedExpression to be called
#define IDE_FLAGS 	OF_NOSIZE | OF_NODRAW

#include "..\..\Common\ExpReturn.hpp"

#define OBJECTRECT CRect(editObject->objectX, editObject->objectY, editObject->objectX + editObject->objectWidth, editObject->objectY + editObject->objectHeight)

//////////// RUNTIME OBJECT ////////////
// Add any member functions or data you want to this class.
// Your extension inherits CRunObject.  See the definition
// for the default member values you have access to.
class ExtObject : public CRunObject
{
public:
	// Constructor (called when Construct creates the object)
	ExtObject(initialObject* editObject, VRuntime* pVRuntime);
	// Destructor (called when Construct destroys the object)
	~ExtObject();

	IRenderer* const renderer;

	//////////////////////////
	// OnFrame: called once per frame just before Draw() (after the events list)
	// OnFrame2: called once per frame just after Draw() (before the events list)
	BOOL		OnFrame();
	BOOL		OnFrame2();
	// Draw: called when Construct wants you to render your object.
	void		Draw();
	// WindowProc is called if your extension creates a window and calls RegisterWindow().
	LRESULT		WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
	BOOL		PreTranslateMessage(MSG* msg);
	// Return default expression editor value and undefined expressions when enabled.
	long		ReturnDefaultValue(LPVAL params, ExpReturn& ret);
	long		ReturnUndefinedExpression(CString& expName, LPVAL params, ExpReturn& ret);
	// Called just after the constructor when your object has been prepared.
	void		OnCreate();
	// Called when a frame changes and your object is global
	void		OnFrameChange(int oldFrame, int newFrame);
	// Called when your object should save/load itself at runtime
	void		Serialize(bin& ar);
	// Data functions
	long		GetData(int id, void* param);
	long		CallFunction(int id, void* param);
	// Debugging
	void		DebuggerUpdateDisplay(ExpStore*& pPrivateVars);
	void		OnDebuggerValueChanged(const char* name, const char* value);

	////////////////////////////////////////////////////
	// ACTIONS, CONDITIONS AND EXPRESSIONS DEFINITIONS
#include "..\..\Common\CommonAceDecl.hpp"

	// Conditions
	long cIsTrophyAchieved( LPVAL params );
	long cIsValidUser( LPVAL params );
	long cIsGuestScore( LPVAL params );
	long cIsGameStorageItemSet( LPVAL params );
	long cIsUserStorageItemSet( LPVAL params );

	// Actions
	long aSetGameID( LPVAL params );
	long aSetGamePrivateKey( LPVAL params );
	long aSetUsername( LPVAL params );
	long aSetUserToken( LPVAL params );

	long aAddAchievedTrophy( LPVAL params );

	long aSetGameStorageItem( LPVAL params );
	long aSetUserStorageItem( LPVAL params );
	long aRemoveGameStorageItem( LPVAL params );
	long aRemoveUserStorageItem( LPVAL params );

	long aLoadScores( LPVAL params );
	long aAddScore( LPVAL params );

	// Expressions
	long eGetGameID( LPVAL params, ExpReturn &ret );
	long eGetGamePrivateKey( LPVAL params, ExpReturn &ret );
	long eGetUsername( LPVAL params, ExpReturn &ret );
	long eGetUserToken( LPVAL params, ExpReturn &ret );

	long eGetErrorMessage( LPVAL params, ExpReturn &ret );

	long eGetTrophyTitle( LPVAL params, ExpReturn &ret );
	long eGetTrophyDescription( LPVAL params, ExpReturn &ret );
	long eGetTrophyDifficulty( LPVAL params, ExpReturn &ret );
	long eGetTrophyAchievedDate( LPVAL params, ExpReturn &ret );

	long eGetGameStorageData( LPVAL params, ExpReturn &ret );
	long eGetUserStorageData( LPVAL params, ExpReturn &ret );

	long eGetScoresCount( LPVAL params, ExpReturn &ret );
	long eGetScoreString( LPVAL params, ExpReturn &ret );
	long eGetScoreSort( LPVAL params, ExpReturn &ret );
	long eGetScoreExtraData( LPVAL params, ExpReturn &ret );
	long eGetScoreUser( LPVAL params, ExpReturn &ret );
	long eGetScoreUserID( LPVAL params, ExpReturn &ret );
	long eGetScoreStoredDate( LPVAL params, ExpReturn &ret );

	////////////////////////////////////////////////////
	// Data members

	GameJoltAPI api;

	int m_LoadScoresCount;
	vector<Score> m_Scores;

	// Use when private variables (OF_PRIVATEVARIABLES) are enabled.
	//vector<ExpStore> privateVars;
};

//////////// EDITTIME INFO ////////////
class EditExt
{
public:

	///////////////////////////
	// Class data
	EditExt(class VEditTime* pVEditTime, class editInfo* pEInfo);
	~EditExt();

	void Draw();
	int  GetMenuIcons(int ACEMenu);
	void Initialize();
	void OnPut();
	void OnRemoved();
	int  OnShowACEMenu(TABLE ACEType);
	BOOL OnSizeObject();
	void Serialize(bin& ar);
	void OnPropertiesUpdate();
	void GetAnimationHandle(int& handle);

	class VEditTime* pEditTime;	// Pointer to Virtual Edittime
	class editInfo*  pInfo;		// Pointer to object edittime info

	int iTexture;		// DX texture

	///////////////////////////
	// Your edittime extension data goes here

	int m_GameID;
	CString m_GamePrivateKey;
	int m_LoadScoresCount;

};

// Internal stuff include
#include "..\..\Common\Internal.hpp"
#include "..\..\Common\Properties.h"

// Only include once
#endif