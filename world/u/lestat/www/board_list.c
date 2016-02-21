/*
  www/cgi-bin/board_list.c
  By Ammy@YSZZ
  2001/04/13
  使用时请确保所列留言板数据文件都存在
 */ 

#include <mudlib.h>

inherit F_CLEAN_UP;
//inherit F_REMOVEANSI;

private mapping vaild_boards = ([
        "ann_b" :       ({"巫师公告栏",0}),
        "nancheng_b" :      ({"南城客栈留言板",1}),
        "dragon_b" :    ({"龙腾四海留言版",1}),
        "honglou_b" :   ({"红楼玉石",1}),
        "jiangjing_b" : ({"五庄观讲经板",1}),
        "moon_b" :      ({"月宫留言板",1}),
        "shengsi_b" :   ({"地府生死簿",1}),
        "shibei_b" :    ({"灵台山石碑",1}),
        "system_b" :    ({"系统公告板",0}),
        "wall_b" :      ({"普陀留言壁",1}),
        "wudidong_b" :  ({"无底洞帐本",1}),        
         "hyd_b" :       ({"火云洞留言板",1}), 
        "xueshan_b" :   ({"雪山留言板",1}),      
        "biwuboard" :        ({"比武留言板",1}),    

]);


string gateway() {
        int i,j=0;
        string str,str_h,str_f,*list;
        string number,master,time;
        mapping notes;
        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();

        list = keys(vaild_boards);
        sort_array(list,1);
        
        str =str_h;
        str+="<table width=100% border=0>";
        str+="<tr><td><span style='font-size:9pt'>";
        str+="&nbsp;&nbsp;"+MUD_NAME+"已经运行了"+"/www/cgi-bin/uptime.c"->report();   
        str+="</span></td>";   
        str+="<td align=right><span style='font-size:9pt'>";
        str+=read_file("/log/counter_for_web");
        str+="&nbsp;&nbsp;</span></td></tr></table>";    

        str += "<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";

        str +=sprintf("
        <tr>
          <td align=center bgcolor='#fafafa' nowrap><b>&nbsp;</b></td>
          <td align=center bgcolor='#fafafa' nowrap><font 
          color='#339900'> 版块 </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 帖子 
            </font> </td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 方式 
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> 最新加入 
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'>σ版主σ</font></td>
        </tr>"
        );

        str += sprintf(
        "<tr> 
          <td bgcolor='#ccff99' colspan='6'><b><span style='font-size:11pt'><font color='#339900'>★ %s★公告区</font></span></b></td>
         </tr>",
         MUD_NAME
         );
        for (i=0;i<2;i++) 
        {
        
                if(i==0) list[i]="ann_b";
                if(i==1) list[i]="system_b";    
                str +="<tr> <td bgcolor='whitesmoke' align=center valign=top><img src='http://202.102.208.206/datang/mud/image/read.gif' height=15 width=15 border=0 hspace=0 alt='New Posts'></td>";
                number="/www/cgi-bin/board_h.c"->gateway(list[i],"num");
                master="/www/cgi-bin/board_h.c"->gateway(list[i],"master");
                time="/www/cgi-bin/board_h.c"->gateway(list[i],"time");
                str +=  sprintf(
                "<td bgcolor='whitesmoke' align=left>%d.<a href=board_read?%s&0&9999>%s</a></td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "</tr>",
                                j,
                                list[i],
                                vaild_boards[list[i]][0],
                                number,
                                vaild_boards[list[i]][1]==1?"读写":"只读",
                                time,
                                master
                                );
        }
                
        str += sprintf(
        "<tr> 
          <td bgcolor='#ccff99' colspan='6'><b><span style='font-size:11pt'><font color='#339900'>★ %s★自由讨论区</font></span></b></td>
         </tr>",
         MUD_NAME
         );
        
        for( i=0;i<sizeof(list);i++) 
        {
        
        if (list[i]=="ann_b" || list[i]=="system_b") continue;
        
        ++j;    
        str +="<tr> <td bgcolor='whitesmoke' align=center valign=top><img src='http://202.102.208.206/datang/mud/image/read.gif' height=15 width=15 border=0 hspace=0 alt='New Posts'></td>";

/*
  the first: board's name ,decribtion,url,order number 
  the second: the number of all posts in this board
  the third:  the limiting of this board
  the 4th:  time of the last post         
  the 5th:  the  master's id of this board
*/

        number="/www/cgi-bin/board_h.c"->gateway(list[i],"num");
        master="/www/cgi-bin/board_h.c"->gateway(list[i],"master");
        time="/www/cgi-bin/board_h.c"->gateway(list[i],"time");
        str +=  sprintf(
        "<td bgcolor='whitesmoke' align=left>%d.<a href=board_read?%s&0&9999>%s</a></td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "</tr>",
                                j,
                                list[i],
                                vaild_boards[list[i]][0],
                                number,
                                vaild_boards[list[i]][1]==1?"读写":"只读",
                                time,
                                master
                                );

        }

        str += "</table></table></center>";
        str +=str_f;
        return str;
}

mapping query_boards() {
        return vaild_boards;
}
