inherit NPC;

int give_jing();

void create()
{
  set_name("王后", ({"wang hou", "hou", "queen"}));
  set ("long", "乌鸡国的王后，终日愁眉苦脸，心思重重。\n");
  set("title", "乌鸡国");
  set("gender", "女性");
  set("age", 40);
  set("combat_exp", 100000);
  set_skill("blade", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);
  set_skill("force", 20);
  set("max_sen", 500);
  set("max_kee", 500);
  set("max_force", 500);
  set("force", 100);
  set("force_factor", 4);

  set("inquiry", ([ "wang": "昨夜菩萨托梦,这一饮一啄,因果报应",
                    "国王": "昨夜菩萨托梦,这一饮一啄,因果报应",
                    "king": "昨夜菩萨托梦,这一饮一啄,因果报应",
                    "菩萨": "我向菩萨求得圣水一瓶,可救陛下",
                    "pusa": "我向菩萨求得圣水一瓶,可救陛下",
                    "圣水": (: give_jing :),
                    "shengshui": (: give_jing :),
                 ]) );

  setup();
 
  carry_object("/d/obj/cloth/gongpao")->wear();
}

int give_jing()
{
  object ob	;
  object me=this_object();
  object who=this_player();

  if (who->query("obstacle/qujing")!="ren")
    {
    message_vision("我这圣水只给取经人,恐怕....\n",me);
    return 1; 
    }
 
  if (who->query("obstacle/wuji")=="done"|| me->query("have_gived")==1)
    {
    message_vision("$N疑惑得说道:我似乎给过你了吧?\n",me);
    return 1;
    }

  ob = new ("d/qujing/wuji2/obj/jing");
  message_vision ("\n$N对$n说道：“恩人，还请早日救得陛下归来！\n",me,who);    message_vision ("\n说着$N取出一匣子，拿出一小瓶来。\n",me,who);  
  ob->move(me);
  me->command_function("give "+who->query("id")+" jing");
  me->set("have_gived",1);

  return 1;
}

