/***************************************************************
 * Name:      Youtube_videos_downloaderApp.cpp
 * Purpose:   Code for Application Class
 * Author:    5271 (PtDsckkkkkkk@protonmail.com)
 * Created:   2021-07-30
 * Copyright: 5271 ()
 * License:
 **************************************************************/

#include "Youtube_videos_downloaderApp.h"

//(*AppHeaders
#include "Youtube_videos_downloaderMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Youtube_videos_downloaderApp);

bool Youtube_videos_downloaderApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Youtube_videos_downloaderFrame* Frame = new Youtube_videos_downloaderFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
