#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("Ð¡ÂíáÌ", ({ "ma zai", "zai" }) );
  set("race", "Ò°ÊÞ");
  set("age", 2);
  set("long", "Ò»Ö»¸ÕÉúÏÂÀ´µÄÐ¡ÂíáÌ£¬ÕýÊ¹¾¡È«ÉíµÄÁ¦ÆøÏëÕ¾ÆðÀ´¡£\n");
  set("per", 10+random(20));
  set("eff_kee", 50);
  set("eff_sen", 50);
  set("combat_exp", 0);
  set("daoxing", 0);

  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 10);


  setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);

        set("chat_msg", ({
            "Ð¡ÂíáÌ·¢³öÇáÇáµÄ½ÐÉù¡£\n",
            "Ð¡ÂíáÌÒ»¸ö²»Ð¡ÐÄ£¬Ë¤µ¹ÔÚµØÉÏ¡£\n",
            "Ð¡ÂíáÌ´­×Å´ÖÆø¡£\n",
            "Ð¡ÂíáÌÌ§ÆðÇ°ÍÈ£¬·ÜÁ¦ÏëÕ¾ÆðÀ´¡£\n",
        }) );

        add_action("do_feed", "feed");
}

int do_feed(string arg)
{
        object me,feeob;
        object hb = this_object();

        me = this_player();
        
   
        if ( !arg || !(feeob=present(arg, me)) )
           return notify_fail("ÄãÒª¸øÐ¡ÂíáÌÎ¹Ê²Ã´³Ô£¿\n");

        else if (arg != "grass") 
           return notify_fail("Õâ¶«Î÷Ð¡ÂíáÌ³Ô²»ÁË¡£\n");  

        else 
                { 
                if (me->query("kee")>10)  me->add("kee",-10); 
                else
                   {
                   me->unconcious();
                   return 1;
                   }

                destruct(feeob);



                if ( random(20) != 0 )
                message_vision("$N¸øÐ¡ÂíáÌÎ¹ÁËÒ»Ð©Çà²Ý£¬Ð¡ÂíáÌ½ò½òÓÐÎ¶µÄ³ÔÁËÆðÀ´¡£\n", me);

                else
                  {
                  object smallhorse;
                  message_vision("Ð¡ÂíáÌ³ÔÁËÐ¡²Ý£¬Ç°ÌãÒ»Ñï£¬Õ¾ÁËÆðÀ´¡£\n" , me,);
                  smallhorse = new (__DIR__"smallhorse");
                  smallhorse->move(environment());
                  destruct(hb);
                  }
                }
        return 1;
}
ÿ
