//------------------------------------------------------------------------------
//	Copyright (c) 2010, Stephan Aßmus <superstippi@gmx.de>.
//	Copyright (c) 2012-2013, Guido Pola.
//
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the "Software"),
//	to deal in the Software without restriction, including without limitation
//	the rights to use, copy, modify, merge, publish, distribute, sublicense,
//	and/or sell copies of the Software, and to permit persons to whom the
//	Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//	DEALINGS IN THE SOFTWARE.
//
//	File Name:		IconView.h
//	Authors:		Guido Pola <prodito@live.com>
//	Description:	
//------------------------------------------------------------------------------
#ifndef TORRENTOR_ICON_VIEW_H
#define TORRENTOR_ICON_VIEW_H


class IconView : public BView 
{
public:
	IconView(const char* MimeType = NULL);
	
	void SetMime(const char* MimeType) { fIconMime = MimeType; }

	virtual void AttachedToWindow();
	virtual void Draw(BRect updateRect);
	virtual BSize MinSize();
	virtual BSize PreferredSize();
	virtual BSize MaxSize();

private:
	BString	fIconMime;
};



#endif // TORRENTOR_ICON_VIEW_H
