//Cracked by Roath
inherit ITEM;
#include <ansi.h>
int do_read(string arg);
void create()
{
      

        set_name(RED "※"HIG"大话西游纪念碑"RED"※" NOR, ({ "jinian bei","bei" }) );
        
        set("unit", "本");
        set("long", "这是一块用来纪录大话西游成名人物的石碑，伴随着访仙求道的
风风雨雨，岁月的流逝，石碑依旧。而上的名字却换了
一代又一代。石碑上刻录着：

             一："CYN"大话西游十大"YEL"富豪"NOR"
             二："CYN"大话西游十大"YEL"解迷高手"NOR"
             三："CYN"大话西游十大"HIR"P K 狂魔"NOR"
             四："CYN"大话西游十大"HIR"N K 高手"NOR"
             五："CYN"大话西游十大"HIC"武学高手"NOR"
             六："CYN"大话西游十大"RED"道行高手"NOR"
             七："CYN"大话西游十大"HIR"内力高手"NOR"
             八："CYN"大话西游"HIM"十大美女"NOR"    
             九："CYN"大话西游十大"GRN"老前辈"NOR"
             十："CYN"大话西游十大"GRN"TASK高手"NOR"  
             
             
             
             
                                           
你可以用(read 标号)来翻看记载。\n");       
        
        set("material","steel");
        set_weight(8888888);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
       string str;
	if(!arg||arg=="") 
	   return notify_fail("你要阅读哪一项排行？\n");
switch(arg)
	{
		case "一": arg ="rich";break;
		case "二": arg = "quests";break;
		case "三": arg = "pker";break;
		case "四": arg = "nker";break;
		case "五": arg = "exp";break;
		case "六": arg = "dx";break;
		case "七": arg = "force";break;
		case "八": arg = "per";break;
		case "九": arg = "age";break;
		case "十": arg = "task";break;		   
		default : arg = "none";break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}