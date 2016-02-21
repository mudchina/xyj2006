inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
 set_name("千年树妖", ({ "shu yao", "yao" }) );
 set("gender", "雄性");
 set("age", 1500);
 set("long",
"这是一个成了精的老榕树，常年餐风饮露！\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 10000);
 set("max_sen", 10000);
 set("force",2500);
 set("max_force",2500);
 set("mana",2500);
 set("max_mana",2500);
 set("force_factor",10);
 set_skill("parry",150);
 set_skill("dodge",70);
        set_skill("lotusmove",70);
 set_skill("unarmed",200);
 set_skill("cuixin-zhang",150);
 map_skill("unarmed","cuixin-zhang");
 map_skill("parry","cuixi-zhang");
        map_skill("dodge","lotusmove");
 set("attitude", "aggressive");
 set("combat_exp", 2000000+random(2000000));
 setup();
 carry_object("/obj/money/gold")->set_amount(20);
  carry_object("/d/obj/baowu/fengzhu");
}
void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="fengzhu" || inv[i]->query("id")=="feng lingzhu")
                {
                   inv[i]->move(me);
                   message_vision("$N头顶冒出一颗绿色的珠子，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",RED+"【谣言】某人："+me->query("name")+"拿到风灵珠了！\n"+NOR,users());
         }
        }
  }
 ::die();
}
