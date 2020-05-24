#include <iostream>
#include <wx/bookctrl.h>
#include <wx/textctrl.h>
#include <wx/wx.h>
#include <wx/wxprec.h>

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
};

class wxImagePanel : public wxPanel
{
    wxBitmap image;

  public:
    wxImagePanel(wxBookCtrl* parent, wxString file, wxBitmapType format) : wxPanel(parent)
    {
        image.LoadFile(file, format);
    }
    void paintNow()
    {
        wxClientDC dc(this);
        dc.DrawBitmap(image, 0, 0, false);
    }
};

class MyFrame : public wxFrame
{
  public:
    wxBookCtrl*   book;
    wxListBox*    listbox1;
    wxTextCtrl*   textLog;
    wxImagePanel* drawpane_in_tab1;
    MyFrame(const wxString& title);
    void OnButton1(wxCommandEvent& event);
    void OnButton2(wxCommandEvent& event);
    void OnListBoxDoubleClick(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

  private:
    DECLARE_EVENT_TABLE()
};

// Declare some IDs. These are arbitrary.
const int BOOKCTRL   = 100;
const int BUTTON1    = 101;
const int BUTTON2    = 102;
const int LISTBOX1   = 103;
const int TEXTBOX1   = 104;
const int FILE_QUIT  = wxID_EXIT;
const int HELP_ABOUT = wxID_ABOUT;

// clang-format off
// Attach the event handlers. Put this after MyFrame declaration.
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(BUTTON1, MyFrame::OnButton1)
    EVT_BUTTON(BUTTON2, MyFrame::OnButton2)
    EVT_LISTBOX_DCLICK(LISTBOX1, MyFrame::OnListBoxDoubleClick)
    EVT_MENU(FILE_QUIT, MyFrame::OnQuit)
    EVT_MENU(HELP_ABOUT, MyFrame::OnAbout)
END_EVENT_TABLE()
// clang-format on

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(_T("My wxWidgets Demo"));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(50, 50), wxSize(800, 600))
{
    // so that images can be loaded
    wxInitAllImageHandlers();

    SetIcon(wxICON(sample));
    wxMenu* fileMenu = new wxMenu;
    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(HELP_ABOUT, _T("&About...\tF1"), _T("Show about dialog"));
    fileMenu->Append(FILE_QUIT, _T("E&xit\tAlt-X"), _T("Quit this program"));
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, _T("&File"));
    menuBar->Append(helpMenu, _T("&Help"));
    SetMenuBar(menuBar);
    CreateStatusBar(2);
    SetStatusText(_T("So far so good."), 0);
    SetStatusText(_T("Welcome."), 1);

    book             = new wxBookCtrl(this, BOOKCTRL);
    drawpane_in_tab1 = new wxImagePanel(book, wxT("image.jpg"), wxBITMAP_TYPE_JPEG);
    new wxButton(drawpane_in_tab1, BUTTON1, _T("Button &1"), wxPoint(680, 30), wxSize(100, 30));
    new wxButton(drawpane_in_tab1, BUTTON2, _T("Button &2"), wxPoint(680, 80), wxSize(100, 30));
    book->AddPage(drawpane_in_tab1, _T("Tab1"), true);

    wxString choices[] = {_T("Washington"), _T("Adams"), _T("Jefferson"), _T("Madison"), _T("Lincoln"),
                          _T("One"),        _T("Two"),   _T("Three"),     _T("Four")};
    wxPanel* panel     = new wxPanel(book);
    listbox1 = new wxListBox(panel, LISTBOX1, wxPoint(0, 0), wxSize(150, 70), 9, choices, wxLB_SORT | wxLB_EXTENDED);
    book->AddPage(panel, _T("Tab2"), false);

    panel               = new wxPanel(book);
    wxBoxSizer* mysizer = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(mysizer);
    textLog = new wxTextCtrl(panel, TEXTBOX1, _T("Log\n"), wxPoint(0, 250), wxSize(100, 50), wxTE_MULTILINE);
    mysizer->Add(textLog, 1, wxEXPAND | wxALL, 5);
    book->AddPage(panel, _T("Debug"), false);
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxString msg;
    msg.Printf(
        _T("About.\n")
        _T("Welcome to %s"),
        wxVERSION_STRING);

    wxMessageBox(msg, _T("About My Program"), wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnButton1(wxCommandEvent& WXUNUSED(event))
{
    // wxMessageBox("Click1", "Click", wxOK | wxICON_INFORMATION, this);
    drawpane_in_tab1->paintNow();
}

void MyFrame::OnButton2(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox("Click2", "Click", wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnListBoxDoubleClick(wxCommandEvent& event)
{
    *textLog << "ListBox double click string is: \n";
    *textLog << event.GetString();
    *textLog << "\n";
}