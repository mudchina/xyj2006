// by HAPP@YSZZ
#include <ansi.h>
#include <tomud.h>
inherit ROOM;
int block_cmd(string);
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
            "southup"    :       __DIR__"sz2jx1",
            "westdown"  :       __DIR__"jn2sz2",        
            ]));

        set("outdoors", "12gong");
        setup();
        
         
}

int valid_leave(object me, string dir)
{
       if (me->query_temp("12gong/cike") == "done")
	{
		   message_vision("\n\n一阵时空的曲扭,你被一股神秘的力量送出了双子宫!\n",me);  
	       message_vision("\n嘿嘿...嘿嘿,天空传来一阵阴森的笑声:雅典娜正等着你呢!\n",me);  
		   message_vision("\n你不由得心里一阵不安!\n\n\n",me);   
		  if((me&&me->query("12gong/jinniu")=="done") && (me&&me->query("12gong/shuangzi")!="done"))
        {
        me->start_busy(3);
        message("chat",PTEXT(HIY+"【黄金十二宫】撒加(saga):"+me->name()+
        "闯过了第三宫：双子座迷宫。。。。。。\n"NOR),users());
        me->set("12gong/shuangzi","done");
        me->add("12gong/number",1);
          me->add("combat_exp", 10000);
tell_object(me,"你得到了十年道行\n");

        }
		  return 1;
	}
		
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
