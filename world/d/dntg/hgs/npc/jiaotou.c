inherit NPC;

void create()
{
  set_name("½û¾ü½ÌÍ·", ({"jinjun jiaotou", "jiaotou"}));
  set("title", "°ÁÀ´¹ú");
  set("gender", "ÄÐÐÔ");
  set("age", 45);

  set("max_gin", 500);
  set("eff_gin", 500);
  set("gin", 500);
  set("max_kee", 500);
  set("eff_kee", 500);
  set("kee", 500);
  set("max_sen", 500);
  set("eff_sen", 500);
  set("sen", 500);

  set("combat_exp", 35000);
  set("daoxing", 15000);

  set_skill("unarmed", 70);
  set_skill("spear", 70);
  set("force", 500);
  set("force_factor", 40);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  setup();
  set("inquiry", ([
]) );

        carry_object("/d/obj/cloth/bingfu.c")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang.c")->wield();

}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{	
  string *ans=({"±ÈÎä","¿´ÈÈÄÖ","µ·ÂÒ","´Ó¾ü", });
  int ans1;



        if( !arg ) return notify_fail("ÄãËµÊ²Ã´£¿\n");
        if (arg=="0"|| arg=="1"|| arg=="2"|| arg=="3") 
           {sscanf(arg,"%d",ans1); arg=ans[ans1];}
        message_vision("$N´ðµÀ£º" + arg + "¡£\n", this_player());
        if( arg== "¿´ÈÈÄÖ" ) 
          {
          command("consider");
          command("say ¿´ÈÈÄÖ¿ÉÒÔ£¬µ«²»×¼´óÉùÐú»©£¬ÈÅÂÒÑµÁ·¡£\n");
          this_player()->set_temp("donghai", 1);
          } 
        else 
          {
          command("say ÄãºúËµÊ²Ã´£¿±ðÀ´µ·ÂÒ£¡\n");
          }
        return 1;
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$Nº°µ½£º£¢ºÃ°¡£¬Äã¸Òµ½ÕâÐÐÐ×£¡¿´ÎÒÃÇÔõÃ´ÊÕÊ°Äã£¡£¢Ëµ°Õµøµø×²×²ÃãÇ¿ÅÀ»ØÑÝÎä³¡¡£\n",me);
  message_vision ("\nÓÖÒ»¸ö$N×ßÁË¹ýÀ´¡£\n",me);
  ob = new (__DIR__"jiaotou");
  ob->move(where);
  destruct (me);
}

void die ()
{
  unconcious();  
}

ÿ
