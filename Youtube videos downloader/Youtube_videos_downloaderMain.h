/***************************************************************
 * Name:      Youtube_videos_downloaderMain.h
 * Purpose:   Defines Application Frame
 * Author:    5271 (PtDsckkkkkkk@protonmail.com)
 * Created:   2021-07-30
 * Copyright: 5271 ()
 * License:
 **************************************************************/

#ifndef YOUTUBE_VIDEOS_DOWNLOADERMAIN_H
#define YOUTUBE_VIDEOS_DOWNLOADERMAIN_H

//(*Headers(Youtube_videos_downloaderFrame)
#include <wx/button.h>
#include <wx/choicdlg.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class Youtube_videos_downloaderFrame: public wxFrame
{
    public:

        Youtube_videos_downloaderFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Youtube_videos_downloaderFrame();

    private:

        //(*Handlers(Youtube_videos_downloaderFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnResterListButtonClick(wxCommandEvent& event);
        void OnAddVideoButtonClick(wxCommandEvent& event);
        void OnDownloadButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Youtube_videos_downloaderFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Youtube_videos_downloaderFrame)
        wxButton* AddVideoButton;
        wxButton* DownloadButton;
        wxButton* ResterListButton;
        wxButton* ShowListButton;
        wxMultiChoiceDialog* MultiChoiceDialog1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* FilePathTextBox;
        wxTextCtrl* YoutubeLinkTextBox;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // YOUTUBE_VIDEOS_DOWNLOADERMAIN_H
