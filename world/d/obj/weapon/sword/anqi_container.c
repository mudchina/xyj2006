//Cracked by Roath
// 凤凰琴  

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);



void create()
{
   set_name("凤凰琴", ({"fenghuang qin","qin","sword"}));
   set_weight(4000);
   if( clonep() ) 
          set_default_object(__FILE__);
   else 
     {
      set("long", "一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝贝了。\n");
      set("orilong", "一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝贝了。\n");
      set("unit", "张");
      set("value", 3000);
      set("material", "leather");
      set("wield_msg", "$N从背后摘下一张$n，捧在手中。\n");
      set("unwield_msg", "$N收起手中的$n，小心翼翼的背回背后。\n");
      set("anqi/allow", 1);
      set("anqi/max", 20);
      set("anqi/now", 0);
     }
     setup();
}

void init()
{                                             
  add_action("do_install", "install");
  add_action("do_uninstall", "uninstall");
}


int do_install(string arg)
{
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("你想装什么？\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
		return notify_fail("你身上没有这东西。\n");
   if (aq->query("name") == me->query("name") ) 
                return notify_fail("装自己？\n");
   if (! aq->query("can_install")) 
        	return notify_fail("这玩艺太大了，装不进去。\n");
   if (who->is_busy()) return notify_fail("你正忙着呢。\n");
   if (me->query("anqi/now") == me->query("anqi/max"))
        	return notify_fail(me->query("name")+"已经装满暗器了。\n");
   if (me->query("anqi/now") >0 && me->query("anqi/type") != aq->query("name") )
        	return notify_fail(me->query("name")+"不能装不同种类的暗器。\n");
   else  
     {
     message_vision( "$N打开"+me->query("name")+"的机关，将一"
		+aq->query("unit")+aq->query("name")+"装了进去。\n",who);
     me->set("anqi/location",base_name(aq));
     who->start_busy(3);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));

     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
       {
        remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
        me->set("anqi/now",me->query("anqi/max"));
        me->set("long",me->query("orilong")+"里面已经装了" 
		+chinese_number(me->query("anqi/now"))
		+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
        aq->set_amount(remain);
         }
     else 
       {
        me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
        me->set("long",me->query("orilong")+"里面已经装了"
		+chinese_number(me->query("anqi/now"))
		+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
        destruct(aq);
        }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob;
   object me=this_object();
   object who=this_player();

   if( !this_object()->id(arg) ) return notify_fail("你想拆什么？\n");
   else if (me->query("anqi/now") ==0) 
		return notify_fail(me->query("name")+"里面什么也没有。\n");
   else 
     {

      ob = new(me->query("anqi/location"));
   if (who->is_busy()) return notify_fail("你正忙着呢。\n");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",me->query("orilong"));
      me->set("anqi/now", 0);
      me->delete("anqi/location");
      me->delete("anqi/type");
      message_vision("$N从"+me->query("name")+"里面拆出一"
		+ob->query("unit")+ob->query("name")+"。\n", who);
      who->start_busy(3);
      return 1;               
     }
  }
