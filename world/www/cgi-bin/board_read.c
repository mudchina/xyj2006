// board_read.c
// author : ken@XAJH
/* 98-8-22 : file create by ken@XAJH
 * 98-8-27 : for suport boards, modify the argment by ken@XAJH.
*/

/*
	www/cgi-bin/board_read.c
	modified by Ammy@dtxy
	2001/04/13
*/	

#include <mudlib.h>

#define BOARD_CAPACITY 1024

//inherit F_REMOVEANSI;
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

string long(int);
string short();
string read(int);
string query_save_file();
void setup();

private mapping notes;

string gateway(string arg) {
        int bn,pn,select=0;
        string str,board;
        string str_h,str_f;
        mapping vaild_board = "/www/cgi-bin/board_list.c"->query_boards();

        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        	
        if( sscanf(arg,"%s&%d&%d",board,pn,bn) == 3 )
                select = 1;

        if( undefinedp(vaild_board[board]) )
                return sprintf("%s<p>留言板(%s)不存在。</p>", str_h,board,str_f);

        set("board_id",board);
        setup();

	str =str_h;
	
        if( !select )
                str += sprintf("%s", read(pn) );
        else
                str += sprintf( "%s", long(bn) );
        
        str +=str_f;
        return str;
}

void create() {
        seteuid( geteuid() );
}

string query_save_file()
{
        string id;
        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

void setup() {
        if( restore() )
                notes = query("notes");
        else
                notes = ([]);
}

string short()
{
        if( !pointerp(notes) || !sizeof(notes) )
                return " [ 没有任何留言 ]";

        return sprintf("[ 共 %d 张留言 ]", sizeof(notes) );
}

string long(int arg)
{
        int i,bof,eof;
        string msg;
        string id,name;

	msg="<table border='0' width='95%'><tr>";
	msg+="<td width='33%' align='left' nowrap><font face='宋体' style='font-size:9pt'>";
	msg+="<a href='board_list.c'>";
	msg+="<img src='http://202.102.208.206/datang/mud/image/open.gif' alt='All Forums' height=15 width=15 border='0'>";
	msg+="&nbsp;留言板主题页面</a><br>";
        msg+="<img src='http://202.102.208.206/datang/mud/image/open_topic.gif' height=15 width=15 border='0'>";
        msg+="<img src='http://202.102.208.206/datang/mud/image/open_topic.gif' height=15 width=15 border='0'>";
	msg+=sprintf(
	"&nbsp;<a href='board_read?%s&0&9999'>%s</a><br>",
		query("board_id"),
		query("name")
	 );

    	msg+="<td align='center' width='33%'><font face='宋体' style='font-size:9pt'>";
	msg+="<center><font face='宋体' style='font-size:9pt'>";
	msg+="<img src='http://202.102.208.206/datang/mud/image/open_topic.gif' alt='新帖子' height=15 width=15 border=0>";
	//msg+=sprintf("&nbsp;<a href='post?%s&%s&p'>加入新帖</a>&nbsp;</font></center>",query("board_id"),query("name"));
    	msg+="</font></td>";
    	msg+="<td align='center' width='33%'></td></tr><tr><td colspan=2></td>";
	msg+="<td align='right'>&nbsp;</td></tr></table>";
	

        if( !pointerp(notes) || !sizeof(notes) ) 
        	return "<p></p><p align=center>"+query("long")+"</p><p></p>";

        eof = arg - 1;

        if( eof > sizeof(notes)-1 )
                eof = sizeof(notes)-1;

        bof = eof - 20;
        if( bof < 0 ) {
                eof = sizeof(notes) > 19 ? 19 : sizeof(notes)-1;
                bof = 0;
        }

	msg+="<table border='0' width='95%' cellspacing='0' cellpadding='0' align='center'>";
	msg+="<tr><td bgcolor='black'>";
    	msg+="<table border='0' width='100%' cellspacing='1' cellpadding='4'>";	
    	msg+="
    	<tr>
        <td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt'>&nbsp;</font></b></td>
       	<td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt' color='green'>序号</font></b></td>
        <td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt' color='green'>标题</font></b></td>
        <td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt' color='green'>作者</font></b></td>
        <td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt' color='green'>阅读次数</font></b></td>
        <td align='center' bgcolor='#fafafa'><b><font face='宋体' style='font-size:9pt' color='green'>发表时间</font></b></td>
        </tr>";
    	
        for( i=eof; i+1>bof; i-- ){

	if (sscanf(notes[i]["author"],"%s(%s)",name,id) !=2)
	{
		id="guest";
		name="妖神客人";
	}	 
                msg += sprintf(
        "<tr>"
        "<td bgcolor='whitesmoke' align=center valign=top>"
        "<img src='http://202.102.208.206/datang/mud/image/read.gif' height=15 width=15 border=0 hspace=0 alt='New Topic'>"
        "</td>"
        "<td bgcolor='whitesmoke' valign='top' align='center'>"
        "<font face='宋体' style='font-size:9pt'>%d</font>"
        "</td>"
        "<td bgcolor='whitesmoke' valign='top' align='left'"
        "<font face='宋体' style='font-size:9pt'>"
        "<a href=board_read?%s&%d>%s %s</a></font></td>"
        "<td bgcolor='whitesmoke' valign='top' align='center'>"
        "<font face='宋体' style='font-size:9pt'><a href=finger?id=%s>%s&nbsp;[%s]</a></font></td>"
        "<td bgcolor='whitesmoke' valign='top' align='center'>"
        "<font face='宋体' style='font-size:9pt'>num</font></td>"
        "<td bgcolor='whitesmoke' valign='top' align='center'>"
        "<font face='宋体' style='font-size:9pt'>%s</font></td>"                
        "</tr>"
        ,
                        i+1,
                        query("board_id"),
                        i+1,
                        notes[i]["sx"],notes[i]["title"],
                        lower_case(id),name,id,
                        ctime(notes[i]["time"]),
                        );
       }                 
	msg +="</table></td></tr><tr><td colspan=5>&nbsp;</td></tr></table>";
	
	msg+="<table border='0' width='100%'><tr><td><td valign='top'>";
	msg+="<td align='center' nowrap>";	
        msg +=  sprintf(
                        "&nbsp;<a href=board_read?%s&0&%d>%s</a>&nbsp;"
"&nbsp;<a href=post?%s&%s&p></a>&nbsp"
                        "&nbsp;<a href=board_list>选择留言板</a>&nbsp"
                        "&nbsp;<a href=board_read?%s&0&%d>%s</a>&nbsp"
                        "</td></td><tr></table>",
                        query("board_id"),
                        bof == 0 ? 9999 : eof - 20 + 1,
                        bof == 0 ? "最后一页>>" : "<<上一页",
                        query("board_id"),
                        query("name"),
                        query("board_id"),
                        eof == sizeof(notes)-1 ? 20 : eof + 20 + 1,
                        eof == sizeof(notes)-1 ? "<<第一页" : "下一页>>",

                        );

        return msg;
}

string read(int arg)
{
        int num=arg;
        string body,myid,*msg,note_body="";
	string id,name;
        myid = query("board_id");

        if( !pointerp(notes) || !sizeof(notes) )
                return "<p align=center>留言板上目前没有任何留言。</p>";

        if( num < 1 || num > sizeof(notes) )
                return "<p align=center>没有这张留言。</p>";

        num--;
        msg = explode(notes[num]["msg"],"\n");
        for( int i=0;i<sizeof(msg);i++ ) {
                note_body += sprintf("%s<br>",msg[i]);
        }

        if( note_body=="" ) note_body= "无内容。<br>";

	
	body="<table border='0' width='95%'>";
	body+="<tr>";
	body+="<td width='50%' align='left' nowrap><font face='宋体' style='font-size:9pt'>";
	body+="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border='0'>&nbsp;<a href='board_list.c'>留言板主题页面</a><br>";
	body+="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border='0'>";
	body+="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border='0'>";

	body +=sprintf(
	"&nbsp;<a href='board_read?%s&0&9999'>%s</a><br>",
		query("board_id"),
		query("name")
	 );
	body +="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border='0'>";
	body +="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border='0'>";
	body +="<img src='http://202.102.208.206/datang/mud/image/open_topic.gif' height=15 width=15 border='0'>";
	body+=sprintf("&nbsp;<font color=blue>%s</font></font></td>",notes[num]["title"]);
	body+="<td align='center' width='50%'>";
	body+="<font face='宋体' style='font-size:9pt'>";  
	body+="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border=0>";
	//body+=sprintf("&nbsp;<a href='post?%s&%s&p'>加入新帖</a>&nbsp;",query("board_id"),query("name")); 
 	body+="<img src='http://202.102.208.206/datang/mud/image/open.gif' height=15 width=15 border=0>";
 	//body+=sprintf("&nbsp;<a href='post?%s&%s&r&%s'>回复帖子</a>&nbsp;",query("board_id"),query("name"),notes[num]["title"]);
 	body+="<br></td></tr>";

	body+="<br></table>";
	
	body+="
	<table border='0' width='95%' cellspacing='0' cellpadding='0' align='center'>
	<tr>
	<td bgcolor='black'>
	<table border='0' width='100%' cellspacing='1' cellpadding='4'>
	<tr>
	<td align='center' bgcolor='#fafafa' width='100'  nowrap><b><font face='宋体' style='font-size:9pt' color='green'>作者</font></b></td>
	<td align='center' bgcolor='#fafafa' width='100%' ><b><font face='宋体' style='font-size:9pt' color='green'>内容</font></b></td>
	<td align=right bgcolor='#fafafa' nowrap>&nbsp;</td>
	</tr>
	";
	if (sscanf(notes[num]["author"],"%s(%s)",name,id) !=2)
	{
		id="guest";
		name="妖神客人";
	}	 
	body+=sprintf(
	"<tr><td bgcolor='whitesmoke' valign='top'>"
	"<font color='black'><a href=finger?id=%s><b>%s<br>%s@dtxy</b></a></font><br>"
	"</td>"
	"<td bgcolor='whitesmoke' colspan='2'valign='top'>"
	"<img src='http://202.119.144.5/~mudadm/mudweb/icon_posticon.gif' border='0' hspace='3'>"
	"<font color='black' face='宋体' style='font-size:9pt'>"
	"发表自&nbsp;-&nbsp;%s</font>" 
        "&nbsp;<a href=finger?id=%s>"
        "<img src='http://202.119.144.5/~mudadm/mudweb/icon_profile.gif' height=15 width=15 alt='用户资料' border='0' align='absmiddle' hspace='6'>"
        "</a>" 
        "&nbsp;<a href=mail?%s>"
        "<img src='http://202.119.144.5/~mudadm/mudweb/icon_email.gif' height=15 width=15 alt='Email' border='0' align='absmiddle' hspace='6'>"
        "</a>" 
        "&nbsp;<a href=post?%s&%s&r&%s>"
        //"<img src='http://202.119.144.5/~mudadm/mudweb/icon_reply_topic.gif' height=15 width=15 alt='回复/引用' border='0' align='absmiddle' hspace='6'>"
        "</a>" 
        "<hr noshade size='1'>"
	"<font color='black' face='宋体' style='font-size:9pt'>"
	"%s</font>"
	"<br><br>------<br>※ Origin : 西游记2006总站 < 202.102.208.188 6666 >"
	"<br>From: %s",
		lower_case(id),name,id,
		ctime(notes[num]["time"]),
		lower_case(id),
		id,
		query("board_id"),
		query("name"),
		notes[num]["title"],
		note_body,
		notes[num]["ip"]
	);

	body+="</td></tr></table></td></tr><tr><td colspan='2'>&nbsp;</td></td>";
	body+="<table border='0' width='100%'><tr><td><td valign='top'>";
	body+="<td align='center' nowrap>";
	num ++;
        body += sprintf(
                        "&nbsp;&nbsp;<a href=board_read?%s&%d>%s</a>"
                        "&nbsp;&nbsp;<a href=board_read?%s&0&%d>返回%s</a>"
                        "&nbsp;&nbsp;<a href=board_read?%s&%d>%s</a>"
                        "&nbsp;",
                        query("board_id"),
                        num == 1 ? sizeof(notes) : num-1,
                        num == 1 ? "最后一篇>>" : "<<上一篇",
                        query("board_id"),
                        num,
                        query("name"),
                        query("board_id"),
                        num == sizeof(notes) ? 1 : num+1,
                        num == sizeof(notes) ? "<<第一篇" : "下一篇>>",

                        );
	body+="</td></tr></table>";
	return body;
}	
