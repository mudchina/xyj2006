// by HAPP@YSZZ
#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "第三宫双子座");
        set ("long", @LONG
  迷恋斯巴达王妃勒达美色的宙斯，为接近她而化身为天鹅，两人生了一对双胞胎-波拉克
斯神子和人之子卡斯托。两人皆是骁勇冒险的武士，经常联手立下大功勋。他们二人也有一
对双胞胎堂弟-伊达斯和林克斯。一天四人准备去抓牛，他们抓了很多牛，并准备平分时，
贪心的伊达斯和林克斯趁波拉克斯，卡斯托兄弟不备时，将牛全部带回去。被激怒的两对双
胞胎大起争执，结果伊达斯用箭将卡斯托刺死。波拉克斯伤心得要随卡斯托赴天国，但却因
为拥有永远的生命而不能如愿。他的悲痛感动了宙斯，乃为他们二人设立星座，分别住在天
国和死亡之国。

LONG);
            set("exits", ([
            "left"    :       __DIR__"szchoose",
            "right"  :       __DIR__"szchoose",        
            ]));

  /*      set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
*/
		set("outdoors", "12gong");
        setup();
        
         
}


int valid_leave(object me,string dir)
{ 
	
        if ( present("shuang zi") && (dir == "right" || dir == "left" ))

        return notify_fail("空荡荡的双子宫深处传来一阵冷笑！\n");
        
	
    new("/d/12gong/npc/shuangzi")->move(environment(me));
    return ::valid_leave(me, dir);
 
        
}


void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
