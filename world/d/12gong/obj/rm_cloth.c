// by happ@YSZZ
#include <ansi.h>

#include <armor.h>

inherit CLOTH;

void create()
{
   set_name(HIY"射手座圣衣"NOR, ({ "sheshou shengyi" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("material", "steel");
     set("armor_prop/armor",60);
     set("no_get","这件黄金圣衣不属于你!\n");

   }
   setup();
}

void init()
{
        object me = this_player();
        ::init();
         if(userp(me)&&!wizardp(me))
         {
       message_vision(HIY"射手座黄金圣衣竟然自动拉紧了弦上的黄金箭，只见阳光突然变强，照得人睁不开眼！\n"NOR,me);
                call_out("greeting",5, me);
}

}
int greeting(object me)
{
   //  if( !me || !visible(me) || environment(me) != environment() ) return 0;
     if (me->query_temp("12gong/cike")=="done")
	{
		 message_vision(HIY"\n\n黄金箭缓缓指向了你,突然离弦射出!!!\n",me);
         message_vision(HIY"你反应不及,被黄金箭穿胸而过.对面的射手座黄金圣衣也随即消失了!\n"NOR,me);
		// me->add("eff_kee",-(query("eff_kee")/2));
		 me->receive_wound("kee",me->query("max_kee")/2+random(me->query("max_kee")/2)-me->query("max_kee")/10);

		 COMBAT_D->report_status(me);
        me->set("12gong/renma","done");
        me->add("12gong/number",1);
		destruct(this_object());   
	}
           else
	{
			   message_vision(HIY"\n\n\n黄金箭缓缓转向了通往山羊宫的路口.\n",me);
			   message_vision(HIY"\n突然,黄金箭就像有人控制一样离弦而出,带着一股强大的小宇宙穿过了封锁通向山羊宫的屏障\n",me);
			   me->set("12gong/renma","done");
        me->add("12gong/number",1);
			   destruct(this_object());
	          
	}
	        me->start_busy(3);
			message("chat",PTEXT(HIY+"\n\n【黄金十二宫】艾俄罗斯(Aiolos):射手座将永远守护女神-雅典娜!\n"NOR),users());
}
