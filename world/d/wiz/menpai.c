//sgzl

#include <net/dns.h>
#include <mudlib.h>
#include <room.h>
inherit ROOM;

int do_look(string arg);
void reset_long();

int *exp = ({0,0,0,0,0,0,0,0,0,0,0,0,0,0});



string *names = ({
           "方寸山三星洞　　",
           "南海普陀山　　　",
           "阎罗地府　　　　",
           "月宫　　　　　　",
           "五庄观　　　　　",
           "陷空山无底洞　　",
           "大雪山　　　　　",
           "东海龙宫　　　　",
});

string long=@LONG

传说各门各派为了光大本门，都将派人来长安招纳人才，
南城客栈老板专开一间雅座，供各派神妖歇脚。
LONG;

void create()
{
set("short", "招贤馆");


set("exits", ([
  "east"   : "/d/wiz/entrance",
]));


set("objects", ([
]));



setup();
//reset_long();
}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	if( !arg ) {
		reset_long();
	}
	command("look");
}

void reset_long()
{
     object *list;
     int i, j, ppl_cnt;
     int pmin,fc,ptuo,hell,moon,wzg,wdd,xshan,sea;
     string str,result;
    
     int num_temp; 
     string name_temp;

     int *num_online = ({0,0,0,0,0,0,0,0,0,0,0,0});

     pmin=0; fc=0; ptuo=0; hell=0; moon=0; 
     wzg=0; wdd=0; xshan=0; sea=0; 

     list = users();
     ppl_cnt = 0;
     j = sizeof(list);
     while( j-- ) 
       {
        if(wizardp(list[j]))  continue;
        str = sprintf("%s\n", list[j]->query("family/family_name"));

        switch(str)
          {
           case "方寸山三星洞\n": num_online[0]++;continue;
           case "南海普陀山\n": num_online[1]++;continue;
           case "阎罗地府\n": num_online[2]++;continue;
           case "月宫\n": num_online[3]++;continue;
           case "五庄观\n": num_online[4]++;continue;
           case "陷空山无底洞\n": num_online[5]++;continue;
           case "大雪山\n": num_online[6]++;continue;
           case "东海龙宫\n": num_online[7]++;continue;
           default:   pmin++;
          } 

        ppl_cnt++;
       }


    for (i=0;i<sizeof(names);i++)
      {
       for (j=i+1;j<sizeof(names);j++)
          {if (num_online[i]<num_online[j]) 
             {
              num_temp=num_online[i];num_online[i]=num_online[j];num_online[j]=num_temp;
              name_temp=names[i];   names[i]=names[j];  names[j]=name_temp;
             }
          }
      }
   
    result =  "\n　　门派　　　在线人数　\n";
    for (i=0;i<sizeof(names);i++) result=result+names[i]+num_online[i]+"\n";
    result=result+"普通百姓：　　　"+pmin+"\n";

    set("long",long+"\n"+result);
}


