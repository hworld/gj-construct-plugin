#ifndef TROPHY_H
#define TROPHY_H

//-----------------------------------------------------------
// Stores all the trophy crap.
//-----------------------------------------------------------
class CTrophy
{

public:

	CTrophy( map<CString,CString> trophyInfo );

	int m_ID;
	CString m_Title;
	CString m_Description;
	CString m_Difficulty;
	CString m_AchievedDate;

};

#endif