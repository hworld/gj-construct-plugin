// Include StdAfx
#include "StdAfx.h"

// Include any used common ACE definitions.
#ifdef RUN_ONLY
#include "Common\CommonAceDef.hpp"
#endif

//////////////////////////////////////////////////////////////////////////////////
// ACE table
//////////////////////////////////////////////////////////////////////////////////

void DefineACES(MicroAceTime* at)
{
	// Define your ACE tables here.
	// Use ADDPARAM before each ADDACT/ADDCND/ADDEXP to add parameters.
	// See the documentation for full details.

	// Note in the display string, %o is your object icon and %0-%9 make up parameters.
	// Note the script name should be a name suitable for the routine as if it were a member function in a
	// scripting language, eg. "Clear Stored Items" -> "ClearStoredItems"

	/////////////////////////////
	// Conditions
	// Format:
	// ADDCND(List name, Category, Display string, Function address, Script name, Flags)
	// ADDCND("My condition", "My category", "%o My condition", &ExtObject::cMyCondition, "MyCondition", 0);

	ADDCND( "Is Valid User", "User", "%o Is the user's information correct?", &ExtObject::cIsValidUser, "IsValidUser", 0 );

	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDCND( "Is Trophy Achieved", "Trophies", "%o Is trophy with ID of %0 achieved?", &ExtObject::cIsTrophyAchieved, "IsTrophyAchieved", 0 );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the scores index." );
	ADDCND( "Is Guest Score", "Scores", "%o Is the score with an index of %0 a guest score?", &ExtObject::cIsGuestScore, "IsGuestScore", 0 );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key to check." );
	ADDCND( "Is Game Storage Item Set", "Data Storage", "%o Is the game storage item (%0) set?", &ExtObject::cIsGameStorageItemSet, "IsGameStorageItemSet", 0 );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key to check." );
	ADDCND( "Is User Storage Item Set", "Data Storage", "%o Is the user storage item (%0) set?", &ExtObject::cIsUserStorageItemSet, "IsUserStorageItemSet", 0 );

	/////////////////////////////
	// Actions
	// Format:
	// ADDCND(List name, Category, Display string, Function address, Script name, Flags)
	// ADDPARAM(PARAM_VALUE, "Example parameter", "Here is an example parameter.");
	// ADDACT("My action", "My category", "Example action (%0)", &ExtObject::aMyAction, "MyAction", 0);
	// ADDPARAM( PARAM_COLOR, "Color 1", "Select a color" );
	// ADDPARAM( PARAM_COLOR, "Color 2", "Select a color" );
	// ADDACT( "Set colors", "Colors", "Set colors to: %1 and %2", &ExtObject::aSetColors, "MyAction", 0 );

	ADDPARAM( PARAM_VALUE, "Game ID", "Enter the game's ID." );
	ADDACT( "Set Game ID", "General", "Set the game's ID to %0", &ExtObject::aSetGameID, "SetGameID", 0 );

	ADDPARAM( PARAM_STRING, "Game Private Key", "Enter the game's private key." );
	ADDACT( "Set Game Private Key", "General", "Set the game's private key to %0", &ExtObject::aSetGamePrivateKey, "SetGamePrivateKey", 0 );

	ADDPARAM( PARAM_STRING, "Username", "Enter the username." );
	ADDACT( "Set Username", "General", "Set the username to %0", &ExtObject::aSetUsername, "SetUsername", 0 );

	ADDPARAM( PARAM_STRING, "User Token", "Enter the user's token." );
	ADDACT( "Set User Token", "General", "Set the user's token to %0", &ExtObject::aSetUserToken, "SetUserToken", 0 );

	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDACT( "Add Achieved Trophy", "Trophies", "Add an achieved trophy (%0) for the stored user", &ExtObject::aAddAchievedTrophy, "AddAchievedTrophy", 0 );

	
	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDPARAM( PARAM_STRING, "Data", "The data you would like to store." );
	ADDACT( "Set Game Storage Item", "Data Storage", "Set game storage item (%0) to (%1)", &ExtObject::aSetGameStorageItem, "SetGameStorageItem", 0 );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDPARAM( PARAM_STRING, "Data", "The data you would like to store." );
	ADDACT( "Set User Storage Item", "Data Storage", "Set user storage item (%0) to (%1)", &ExtObject::aSetUserStorageItem, "SetUserStorageItem", 0 );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDACT( "Remove Game Storage Item", "Data Storage", "Remove game storage item (%0)", &ExtObject::aRemoveGameStorageItem, "RemoveGameStorageItem", 0 );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDACT( "Remove User Storage Item", "Data Storage", "Remove user storage item (%0)", &ExtObject::aRemoveUserStorageItem, "RemoveUserStorageItem", 0 );


	ADDPARAMCOMBO( "User's Scores?", "Just get the user's scores?", "No|Yes" );
	ADDPARAM( PARAM_VALUE, "Table ID", "The high score table to pull scores for. Leave blank for primary table." );
	ADDPARAM( PARAM_VALUE, "Limit", "The number of scores to pull. Leave blank for default." );
	ADDACT( "Load Scores", "Scores", "Load the scores. For just the stored user? (%0) Table ID: %1 Limit: %2", &ExtObject::aLoadScores, "LoadScores", 0 );

	ADDPARAM( PARAM_STRING, "Score String", "Enter what you would like the score to be on the site." );
	ADDPARAM( PARAM_VALUE, "Score Sort", "Enter a numerical sorting value to associate with this score." );
	ADDPARAM( PARAM_STRING, "Extra Data", "Enter any extra data you would like to associate with this score." );
	ADDPARAM( PARAM_STRING, "Guest Name", "Enter the guest's name if this is a guest score. Leave blank if user score." );
	ADDPARAM( PARAM_VALUE, "Table ID", "The high score table to attach this score to. Leave blank for primary table." );
	ADDACT( "Add Score", "Scores", "Add high score. Score: %0 Sort: %1 Extra Data: %2 Guest: %3 TableID: %4", &ExtObject::aAddScore, "AddScore", 0 );

	/////////////////////////////
	// Expressions
	// ADDEXP(List name, Category, Display string, Function address, Flags)
	// ADDEXP("My expression", "My category", "MyExpression", &ExtObject::eMyExpression, RETURN_INTEGER);
	// ADDPARAM( PARAM_VALUE, "Ratio", "Value between 0 (color 1) and 1 (color 2)" );
	// ADDEXP( "Get color", "Colors", "Color", &ExtObject::eGetColor, RETURN_INTEGER );

	ADDEXP( "Get Game ID", "General", "GetGameID", &ExtObject::eGetGameID, RETURN_INTEGER );
	ADDEXP( "Get Game Private Key", "General", "GetGamePrivateKey", &ExtObject::eGetGamePrivateKey, RETURN_STRING );
	ADDEXP( "Get Username", "General", "GetUsername", &ExtObject::eGetUsername, RETURN_STRING );
	ADDEXP( "Get User Token", "General", "GetUserToken", &ExtObject::eGetUserToken, RETURN_STRING );

	ADDEXP( "Get Error Message", "Debugging", "GetErrorMessage", &ExtObject::eGetErrorMessage, RETURN_STRING );


	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDEXP( "Get Trophy Title", "Trophies", "GetTrophyTitle", &ExtObject::eGetTrophyTitle, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDEXP( "Get Trophy Description", "Trophies", "GetTrophyDescription", &ExtObject::eGetTrophyDescription, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDEXP( "Get Trophy Difficulty", "Trophies", "GetTrophyDifficulty", &ExtObject::eGetTrophyDifficulty, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Trophy ID", "Enter the trophy ID." );
	ADDEXP( "Get Trophy Achieved Date", "Trophies", "GetTrophyAchievedDate", &ExtObject::eGetTrophyAchievedDate, RETURN_STRING );


	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDEXP( "Get Game Storage Data", "Data Storage", "GetGameStorageData", &ExtObject::eGetGameStorageData, RETURN_STRING );

	ADDPARAM( PARAM_STRING, "Key", "Enter the item's key." );
	ADDEXP( "Get User Storage Data", "Data Storage", "GetUserStorageData", &ExtObject::eGetUserStorageData, RETURN_STRING );


	ADDEXP( "Get Scores Count", "Scores", "GetScoresCount", &ExtObject::eGetScoresCount, RETURN_INTEGER );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score String", "Scores", "GetScoreString", &ExtObject::eGetScoreString, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score Sort", "Scores", "GetScoreSort", &ExtObject::eGetScoreSort, RETURN_INTEGER );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score Extra Data", "Scores", "GetScoreExtraData", &ExtObject::eGetScoreExtraData, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score User", "Scores", "GetScoreUser", &ExtObject::eGetScoreUser, RETURN_STRING );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score User ID", "Scores", "GetScoreUserID", &ExtObject::eGetScoreUserID, RETURN_INTEGER );

	ADDPARAM( PARAM_VALUE, "Score Index", "Enter the score's index." );
	ADDEXP( "Get Score Stored Date", "Scores", "GetScoreStoredDate", &ExtObject::eGetScoreStoredDate, RETURN_STRING );

	// This line includes your common ACEs as specified in Main.h
#include "Common\CommonAceTable.hpp"
}


