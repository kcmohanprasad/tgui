//-----------------------------------------------------------------------------
// This source file is part of TGUI (Tiny GUI)
//
// Copyright (c) 2006 Tubras Software, Ltd
// Also see acknowledgements in Readme.html
//
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights to 
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
// of the Software, and to permit persons to whom the Software is furnished to 
// do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//-----------------------------------------------------------------------------
#include <tgui.h>
namespace TGUI
{

    bool TGMessagebox::closeMessageBox(const TGEventArgs& args)
    {
        TGSystem::getSingleton().destroyControl(this);
        return true;
    }


    TGMessagebox::TGMessagebox(string msg, string caption) : TGWindow(TGSystem::getSingleton().getActiveScreen(),caption)
    {
        m_message = msg;
        m_caption = caption;
        TGLabel	*l = new TGLabel(this,msg, 20, 20);
        TGButton	*b = new TGButton(this, 0, 0, 100, 25, "Ok");
        resize((l->x2 - l->x1) + 40, 80);
        l->center();
        b->move(0, l->y2 + 15);
        b->center(true, false);
        resize(x2 - x1 + 1, y2 - y1 + 16 + b->y2 - b->y1);
        b->addEventHandler(TGEvent::MouseClicked,new TGEventHandler(&TGMessagebox::closeMessageBox,this));
        center();
        hide();
    }

    TGMessagebox::~TGMessagebox()
    {
    }


    void TGMessagebox::show()
    {
        makeExclusive();
        TGControl::show();
    }
}