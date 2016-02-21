/*
	www/cgi-bin/inc_header.c
	Created by Ammy@YSZZ
	2001/04/13
	在每个页面的顶部调用
*/
	
#include <mudlib.h>

//inherit F_REMOVEANSI;

string gateway()
{
        string ret;
        
        ret="<head><title>"+MUD_NAME+"在线查询</title>\n";
        ret+="<link rel='stylesheet' href='../style.css'>\n";
        ret+="</HEAD>\n";
        
        ret+="\n";
        ret+="<table align='center' border='0' cellPadding='0' cellSpacing='0'
width='100%'>\n";
        //ret+="<tr>\n";
        //ret+="<td valign='top' width='50%'><a href='http://floveu.126.com'><img
//alt='西游记2006主页' border='0'
//src='http://202.119.144.5/~mudadm/mudweb/FLOG_YSZZ.gif'></a></td>\n";
        ret+="<td align='center' valign='top' width='50%'>\n";
        ret+="    <table border='0' cellPadding='2' cellSpacing='0'>\n";
        ret+="          <tr>
                        <td align='center'><font face='宋体'
style='font-size:9pt'><b><a href='/index.html'>西游记2006在线查询系统</a></b></font></td>
                        </tr>\n";
        ret+="<tr>
          <td align='center'><a href='board_list.c'>留言板</a>
            | <a href='wizlist.c'>巫师列表</a> | <a href='who.c'>在线用户</a>
            | <a href='topn.c'>在线高手</a> | <a href='topten.c'>TOPTEN</a>
            | <a href='mudlist.c'>连线泥巴</a></td>
          </tr>\n";
        //ret+="<form action='login.c' method='post' id=login name=login>\n";
        //ret+="<tr><td align='center'><table><tr>\n";
        //ret+="<td><b>用户:</b><br><INPUT type='text' name='name' size='10' value='' 
//class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>\n";
        //ret+="<td><b>密码:</b><br><INPUT type='password' name='pass' size='10' value=''
//class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>\n";
        //ret+="<td valign='bottom'><INPUT
//src='http://202.119.144.5/~mudadm/mudweb/button_login.gif' type='image'
//value='Login' name='submit' type='submit' border=0 hspace=4></td>\n";
        //ret+="</tr>\n";
        //ret+="<tr><td colspan='3' align='center'><font face='宋体'
//style='font-size:9pt'><a href=passwd.c>忘记你的密码？</a></font></td></tr>\n";
        //ret+="</table></td></tr></form></table></td></tr></table>\n";
        return ret;                             
}
                        
                                
