/***************************************************************
 * Name:      Youtube_videos_downloaderMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    5271 (PtDsckkkkkkk@protonmail.com)
 * Created:   2021-07-30
 * Copyright: 5271 ()
 * License:
 **************************************************************/

#include "Youtube_videos_downloaderMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <list>

using namespace std;

//(*InternalHeaders(Youtube_videos_downloaderFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

bool isUsingWindows = false;
list<string> videos;

#ifdef _WIN32
    isUsingWindows = true;
#endif // _WIN32

//(*IdInit(Youtube_videos_downloaderFrame)
const long Youtube_videos_downloaderFrame::ID_TEXTCTRL1 = wxNewId();
const long Youtube_videos_downloaderFrame::ID_TEXTCTRL2 = wxNewId();
const long Youtube_videos_downloaderFrame::ID_BUTTON1 = wxNewId();
const long Youtube_videos_downloaderFrame::ID_BUTTON2 = wxNewId();
const long Youtube_videos_downloaderFrame::ID_BUTTON3 = wxNewId();
const long Youtube_videos_downloaderFrame::ID_BUTTON4 = wxNewId();
const long Youtube_videos_downloaderFrame::idMenuQuit = wxNewId();
const long Youtube_videos_downloaderFrame::idMenuAbout = wxNewId();
const long Youtube_videos_downloaderFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Youtube_videos_downloaderFrame,wxFrame)
    //(*EventTable(Youtube_videos_downloaderFrame)
    //*)
END_EVENT_TABLE()

Youtube_videos_downloaderFrame::Youtube_videos_downloaderFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Youtube_videos_downloaderFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,240));
    SetMinSize(wxSize(400,240));
    SetMaxSize(wxSize(400,240));
    FilePathTextBox = new wxTextCtrl(this, ID_TEXTCTRL1, _("Path to the youtube-dl file"), wxPoint(16,16), wxSize(368,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    YoutubeLinkTextBox = new wxTextCtrl(this, ID_TEXTCTRL2, _("Youtube video URL"), wxPoint(16,56), wxSize(368,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    ShowListButton = new wxButton(this, ID_BUTTON1, _("Show list of URLs"), wxPoint(16,96), wxSize(144,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ResterListButton = new wxButton(this, ID_BUTTON2, _("Reset the list"), wxPoint(16,128), wxSize(144,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    DownloadButton = new wxButton(this, ID_BUTTON3, _("Download the videos"), wxPoint(240,96), wxSize(144,26), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    AddVideoButton = new wxButton(this, ID_BUTTON4, _("Add video to the list"), wxPoint(16,160), wxSize(144,24), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnTextCtrl1Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnResterListButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnDownloadButtonClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnAddVideoButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Youtube_videos_downloaderFrame::OnAbout);
    //*)

    if (!isUsingWindows) { FilePathTextBox->Enable(false); }
}

Youtube_videos_downloaderFrame::~Youtube_videos_downloaderFrame()
{
    //(*Destroy(Youtube_videos_downloaderFrame)
    //*)
}

void Youtube_videos_downloaderFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Youtube_videos_downloaderFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Youtube_videos_downloaderFrame::OnTextCtrl1Text(wxCommandEvent& event)
{

}

void Youtube_videos_downloaderFrame::OnButton1Click(wxCommandEvent& event)
{

}

void Youtube_videos_downloaderFrame::OnResterListButtonClick(wxCommandEvent& event)
{

}

void Youtube_videos_downloaderFrame::OnAddVideoButtonClick(wxCommandEvent& event)
{
    string videoURL = YoutubeLinkTextBox->GetValue().ToStdString();

    bool isValid = true;

    if (videoURL.substr(0, 8) == "https://")
    {
        if (videoURL.substr(8, 24) != "www.youtube.com/watch?v=") { isValid = false; }
        else
        {
            if (videoURL.length() != 43) { isValid = false; }
        }
    }
    else
    {
        if (videoURL.substr(0, 24) != "www.youtube.com/watch?v=") { isValid = false; }
        else
        {
            if (videoURL.length() != 35) { isValid = false; }
        }
    }

    if (isValid)
    {
        videos.assign(1, videoURL);
    }
    if (!isValid)
    {
        wxMessageBox("Given video URL is invalid. \nPlease enter a valid URL.", "Error");
    }
}

void Youtube_videos_downloaderFrame::OnDownloadButtonClick(wxCommandEvent& event)
{

}
