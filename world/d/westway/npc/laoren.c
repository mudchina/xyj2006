// created by snowcat on 4/9/1997
// laoren.c

int give_it ();

inherit NPC;

void create()
{
  set_name("青髯老人", ({"lao ren", "lao"}) );
  set("gender", "男性" );
  set("age", 81);
  set("long","一位面目慈祥的青髯老人。\n");

  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("combat_exp", 10000+random(5000));
  set("str", 35);
  set("per", 45);
  set("attitude","peaceful");
  set("inquiry", ([
        "book" : (: give_it :),
        "guide": (: give_it :),
        "story": (: give_it :),
        "书"   : (: give_it :),
        "传说" : (: give_it :),
      ]));
  setup();
}

void init()
{
  object who;
  ::init();
  if (interactive(who = this_player()))
  {
     call_out("looking", 2, who);
  }
}

void looking(object who)
{
  object me;
  me = this_object();

  if (! who || environment(who) != environment())
    return;

  message_vision ("$N微微睁开眼，看了$n一眼。\n",me,who);
}

int give_it()
{
  string dir;
  object me;
  object who;
  object story;
  me = this_object();
  who = this_player();

  if (who->query_temp("laoren_has_given"))
  {
    message_vision ("$N轻轻向$n摇了摇头：已经给过你了。\n",me,who);
  }
  else
  {
    story = new ("/d/obj/books-nonskill/book-qujing");
    story->move(who);
    message_vision ("$N在洞壁角落拿出一卷东西，递给$n，然后慢慢闭上眼。\n",me,who);
    who->set_temp("laoren_has_given",1);
  }
  return 1;
}


int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
        
 if((string)ob->query("name")=="宝物图一" || (string)ob->query("name")=="宝物图二")
        {
         command("smile");
         command("say 这位" + RANK_D->query_respect(me) +"真是有心人，我就赠一礼物予你。");
        call_out("destroy", 1, ob);
        lw->move(me);
        
        return 1;       
        }
 }
void destroy(object ob)
{
        destruct(ob);
        return;

}
