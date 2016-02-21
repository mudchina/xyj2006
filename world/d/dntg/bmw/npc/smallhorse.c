#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("Ð¡Âí¾Ô", ({ "ma ju", "ju" }) );
  set("race", "Ò°ÊÞ");
  set("age", 5);
  set("long", "Ò»Ö»ÉÐÎ´³¤´óµÄÐ¡Âí¾Ô¡£\n");
  set("per", 10+random(20));
  set("kee", 100);
  set("max_kee", 100);
  set("sen", 100);
  set("max_sen", 100);
  set("combat_exp", 4000);
  set("daoxing", 4000);

  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("ride/msg", "Ç£");
  set("ride/dodge", 20);
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
            "Ð¡Âí¾ÔÇáÇáµÄºßºßÁË¼¸Éù¡£\n",
            "Ð¡Âí¾ÔÄ¦²Á×ÅÇ°Ìã¡£\n",
            "Ð¡Âí¾ÔÒ»¸±ÎÞ¾«´ò²ÉµÄÑù×Ó¡£\n",
        }) );

        add_action("do_qian", "qian");
        add_action("do_mount", "mount");
}

int do_qian(string arg)
{
        object me = this_object();
        object who = this_player();


        if (arg != me->query("id"))
         return 0;


        else 
            { 
            if (who->query("kee")>50)  who->add("kee",-50); 
            else
               {
               who->unconcious();
               return 1;
               }

            if ( me->query("kee") == 100)
                {

                if ( random(20) != 0 )
                message_vision("$NÇ£×ÅÐ¡Âí¾ÔÁïÁËÒ»È¦¡£\n", who);

                else
                     {
                     object smallhorse;
                     message_vision("$NÒ»ÉùË»Ãù£¬·ÜÌã¼²±¼¡£\n" , me,);
                     me->add("max_kee",200);
                     me->add("eff_kee",200);
                     me->add("kee",200);
                     }
                }
            else  message_vision("$NÇ£×ÅÐ¡Âí¾ÔÁïÁËÒ»È¦£¬µ«Ð¡Âí¾ÔÒÀÈ»ÎÞ¾«´ò²É¡£\n", who);

             }
        return 1;

}

int do_mount(object me)
{
        object who = this_player();
        me = this_object();

        if (me->query("kee")<200)  
           {
            message_vision("Ð¡Âí¾Ô²Ò½ÐÒ»Éù£¬ÂÊµ¹ÔÚµØ¡£\n\n", me);
            me->unconcious();
            return 1;
           }
}

ÿ