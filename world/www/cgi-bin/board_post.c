// file : web_post.c
// function : use web post
// author : ken@XAJH
/* 98-8-27 : file rename to board_post.c by ken@XAJH
 */

/* 
	www/cgi-bin/board_post.c
	modified by ammy@YSZZ
	2001/04/12
	改善界面及部分功能
*/	
 

#include <mudlib.h>
#include <net/config.h>
#include <net/dns.h>

#define BOARD_CAPACITY 1024
#define BOARD_PATH "/obj/board/"

inherit F_SAVE;
inherit F_DBASE;

private mapping *notes;

string result(string);

void create();
void setup();
void post(string,string,string method,string,string);

string gateway(string);
private string HTML_encode(string);
int tochinese(string,int);

void create() {
//        seteuid( geteuid() );
        seteuid(ROOT_UID);
}

void setup() {
        restore();
}

string query_save_file()
{
        string id;
//        if( !stringp(id = query("board_id")) ) return 0;
        id=query("board_id");
        return DATA_DIR + "board/" + id;
}

string gateway(string args) {
        object ob;
        string id,pass,password,title,text,board,method,submit;
        mapping vaild_boards; 
        string sucess;   

        if( !args ) return result("请您先添好表格。0 ");

        if( sscanf(args,"board=%s&method=%s?id=%s&pass=%s&title=%s&text=%s&submit=%s",
                                        board,method,id,pass,title,text,submit) != 7 )
// 因为post.c 中submit值一并传出
// 故增加 submit用来接收多余部分
// Ammy@YSZZ 2001/04/12/                                     
                return result("请您先添好表格。1 ");

        vaild_boards = ("/www/cgi-bin/board_list.c")->query_boards();
        if( undefinedp(vaild_boards[board]) )
                return result("请您先添好表格。 2");

        if( !vaild_boards[board][1] )
                return result( sprintf("%s是只读型
，不能发表文章。",vaild_boards[board][0])     );

        ob = new(LOGIN_OB);
        ob->set("id", id);

        if( !ob->restore() )
                return result("没有这个玩家，或未填妥表格。");

        password = ob->query("password");
        if( crypt(pass, password) != password )
                return result("密码错误，或未填妥表格。");
        post(
board,method,sprintf("%s(%s)",ob->query("name"),id),HTML_encode(title),HTML_encode(text
) );
        destruct(ob);
	
	sucess="<html><head><title>成功发表</title>";
	sucess+=sprintf(
	"<meta http-equiv='refresh' content='1;URL=/cgi-bin/board_read?%s&0&9999'>",
	board);
	sucess+="</head><body bgcolor='#FFFFFF' text='#000000'>";
	sucess+="<p align=center><br><br><br>留言成功加入，谢谢您的参与.<br>";
	sucess+="一秒钟后自动返回留言板……<br></p>";
	sucess+="</body></html>";	
        return sucess;

}

private string HTML_encode(string str)
{
        string retval = "";
        int len = strlen(str);

        for(int i=0; i<len; i++)
                {
                switch(str[i])
                        {
                                case '%':
                                        retval +=" ";
                                        retval[strlen(retval)-1] =tochinese(str,i+1);
                                        i+=2;
                                        break;
                                case '&':
                                        retval += "&amp;";
                                        break;
                                case '+':
                                        retval += " ";
                                        break;
                                case '?':
                                        retval += "？";
                                        break;
                                case '<':
                                        retval += "&lt;";
                                        break;
                                case '>':
                                        retval += "&gt;";
                                        break;
                                case '"':
                                        retval += "&quot;";
                                        break;
                                default:
                                        retval += str[i..i];
                                        break;
                        }
        }
        return retval;
}

void post(string id,string method,string who,string title,string text)
{
        mapping note;
        set("board_id",id);
        setup();

        notes = query("notes");
        note = allocate_mapping(5);
        note["title"] = title;
	if (method=="r") note["sx"] = "Re:";        
        else note["sx"] = "◆";
        note["author"] = who;
        note["msg"] = text;
        note["time"] = time();
        note["ip"] = "Web 浏览";

        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        // Truncate the notes if maximum capacity exceeded.
        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

        set("notes", notes);
        save();

        (BOARD_PATH+id)->setup();
        return;
}

int tochinese(string str,int index)
{    int ch;

    if (48 <= str[index] && str[index]<= 57)
       ch = str[index]-48;
    else
        if (97<=str[index]&&str[index]<=102)      
           ch=str[index]-97+10;
        else
           if (65<=str[index]&&str[index]<=70)      
               ch=str[index]-65+10;
   ch = ch *16;
   if (48 <= str[index+1] && str[index+1]<= 57)
         ch = ch+str[index+1]-48;
    else
        if (97<=str[index+1]&&str[index+1]<=102)      
           ch=ch+str[index+1]-97+10;
        else
           if (65<=str[index+1]&&str[index+1]<=70)      
               ch=ch+str[index+1]-65+10;
    return ch;
}
