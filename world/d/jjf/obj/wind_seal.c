#include <skill.h>
#include <ansi.h>

//inherit ITEM;
inherit COMBINED_ITEM;
int random_go(object victim,string* dirs);
void doblow(object);

void create()
{
        set_name("神霄风法符", ({"wind seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“风”字。\n");
         set("base_unit","张");
        set("unit", "张");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	set_amount(1);
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N手中的$n突发红光，符咒渐渐淡去不见了。\n",where,me);
        destruct(me);
}

void invocation(object who)
{
	int i,a,b,c;
	
	a=who->query("combat_exp");
	b=(int)who->query_skill("spells")*(int)who->query_skill("spells")*(int)who->query_skill("spells");
	c=(int)who->query("mana_factor")*(int)who->query("mana_factor")*(int)who->query("mana_factor");
	i=a+b+c;

	this_object()->set("ap",i);
	return;
}
int ji_ob(object victim)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

	int damage, ap, dp;
	
	if(me->is_busy())
		return notify_fail("你正忙着呢，无法祭神霄风法符。\n");
	if( !victim)
		return notify_fail("你想祭的人不在这里。\n");
	if( where->query("no_magic"))
		return notify_fail("这里不能祭神霄风法符。\n");
	if( !me->is_fighting())
		return notify_fail("只有战斗中才能祭神霄风法符。\n");
	if( !userp(victim))
		return notify_fail("你只能将神霄风法符祭在玩家身上。\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制神霄风法符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭神霄风法符。\n");

	message_vision(HIC"\n$N大喊一声“着”，手一挥，祭出了一张$n。。。\n"NOR, me, seal);
message_vision(HIC"$n「呼」地一下飞到半空，只见平地狂风乍起，夹头夹脑地袭向$N。\n"NOR, victim,seal);


	add_amount(-1);
	ap= (int)seal->query("ap");
	dp= (int)victim->query("daoxing")+(int)victim->query("combat_exp");
	dp+= (int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_kar()/20;


	if(random(ap+dp) > dp/2)	{

	message_vision(HIC"\n$N脚下一个不稳，如断线的鹞子般飞了出去。\n"NOR,victim);
			call_out("do_blow",1,victim);
			me->start_busy(2);
			victim->start_busy(2);
	}else{
		message_vision(HIC"\n谁知$N如磐石般而立，毫不为其所动。\n"NOR,victim);
	
	}
	
        if( !victim->is_fighting(me) ) {
                if( living(victim) ) {
                        if( userp(victim) ) victim->fight_ob(me);
                        else
				victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }
	me->add("mana",-50);

        me->start_busy(1+random(2));
        
	return 1;
}

int ji (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+name+"？\n");

  victim=present(target,environment(me));
  return(seal->ji_ob(victim));
//  return 1;
}

void do_blow(object victim)
{
	string* dirs
	=({"/d/qujing/bibotan/", "/d/qujing/baotou/", "/d/qujing/baoxiang/",
"/d/qujing/biqiu/", "/d/qujing/chechi/", "/d/qujing/dudi/", "/d/qujing/fengxian/",
"/d/qujing/firemount/", "/d/qujing/jilei/", "/d/qujin/jindou/", "/d/qujing/jingjiling/",
"/d/qujing/jinping/", "/d/qujing/jisaiguo/", "/d/qujing/maoying/", "/d/qujing/jisaiguo/",
"/d/qujing/qilin/", "/d/qujing/pansi/", "/d/qujing/pingding/", "/d/qujing/qinfa/",
"/d/qujing/qinglong/", "/d/qujing/tontian/", "/d/qujing/wudidong/", "/d/qujing/wuji/",
"/d/qujing/xiaoxitian/", "/d/qujing/yinwu/", "/d/qujing/yuhua/", "/d/qujing/zhujie/",
"/d/qujing/zhuzi/" });

	random_go(victim,dirs);
	destruct(this_object());
	return;
}
int random_go(object victim, string* dirs)
{
        int             i, j, k;
        object  newob;
        mixed*  file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }
    if( (newob=load_object(dirs[i]+file[j][0])) )   {
                victim->move( newob ); 
        }
        else  {
		       random_go(victim,dirs);
        }

        return 0;
}

