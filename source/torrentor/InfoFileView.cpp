//------------------------------------------------------------------------------
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
//	File Name:		InfoFileView.h
//	Authors:		Guido Pola <prodito@live.com>
//	Description:	
//------------------------------------------------------------------------------
#include <libtransmission/transmission.h>
#include <libtransmission/utils.h>

#include <ColumnTypes.h>
#include <FileColumn.h>
#include <CheckBoxColumn.h>
//#include <locale/Country.h>


#include "TorrentObject.h"
#include "InfoFileView.h"

#include <stdio.h>

enum
{
	COLUMN_FILE_NAME	= 0,
//	COLUMN_FILE_PRIORITY,
	COLUMN_FILE_DOWNLOAD,
};


#include "IconUtil.h"


InfoFileView::InfoFileView(const TorrentObject* torrent)
	:	BColumnListView("InfoFileView", 0, B_PLAIN_BORDER, true),
		fTorrent(torrent)
{
	SetColumnFlags(B_ALLOW_COLUMN_RESIZE);
	SetSortingEnabled(false);
	
	//
	//
	//
	AddColumn(new FileColumn("Name", 400, 400, 500), COLUMN_FILE_NAME);
	AddColumn(new CheckBoxColumn("DL", 40, 40, 40), COLUMN_FILE_DOWNLOAD);
	//AddColumn(new BStringColumn("Name", 180, 50, 500, B_TRUNCATE_MIDDLE), COLUMN_FILE_NAME);
	//AddColumn(new BStringColumn("Priority", 180, 50, 500, B_TRUNCATE_MIDDLE), COLUMN_FILE_PRIORITY);
	
	//AddColumn(new GraphColumn("Progress", 180, 50, 500), COLUMN_PEER_PROGRESS);
	
	//
	//
	//
	int FileCount = fTorrent->Info()->fileCount;
	tr_file* fileList = fTorrent->Info()->files;
	
	for( int i = 0; i < FileCount; i++ )
	{
		char FormatBuffer[128] = { 0 };
		BRow* row = new BRow(FILE_COLUMN_HEIGHT);
		
		const char* name = fTorrent->IsFolder() ? (strchr(fileList[i].name, '/') + 1) : fileList[i].name;
		
		//
		//
		//
		BString FileExtension = B_EMPTY_STRING;
		BString FilePath 	  = fileList[i].name;
		FilePath.CopyInto(FileExtension, FilePath.FindLast('.') + 1, FilePath.CountChars());
		
		
		const char* info = tr_formatter_mem_B(FormatBuffer, fileList[i].length, sizeof(FormatBuffer));;
		const BBitmap* icon = GetIconFromExtension(FileExtension);
		
		row->SetField(new FileField(icon, name, info), COLUMN_FILE_NAME);
		row->SetField(new CheckBoxField( fileList[i].dnd == false ), COLUMN_FILE_DOWNLOAD);
		
		////row->SetField(new BIntegerField(PeerStatus[i].progress * 100.0), COLUMN_PEER_PROGRESS);
		
		AddRow(row, i);		
	}

/*


void           tr_torrentPeersFree( tr_peer_stat * peerStats,
*/
}
