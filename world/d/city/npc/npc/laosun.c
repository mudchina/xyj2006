// rewritten by snowcat on 5/23/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("laosun");
  set_name("老孙", ({"lao sun", "sun"}));
  set("title","皮货店老板");
  set("gender", "男性");
  set("age", 58);
  set("long","一位长得瘦猴似的老头。\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
  set_skill("dodge", 30);
  set("vendor_goods", ([
         "whitehair" : "/d/obj/magic/hwhite",
         "blackhair" : "/d/obj/magic/hblack",
         "maroonhair" : "/d/obj/magic/hmaroon",
         "amberhair" : "/d/obj/magic/hamber",
         "scarlethair" : "/d/obj/magic/hscarlet",
         "magentahair" : "/d/obj/magic/hmagenta",
         "violethair" : "/d/obj/magic/hviolet",
         "pinkhair" : "/d/obj/magic/hpink",
         "indigohair" : "/d/obj/magic/hindigo",
         "bluehair" : "/d/obj/magic/hblue",
         "brownhair" : "/d/obj/magic/hbrown",
         "greenhair" : "/d/obj/magic/hgreen",
         "yellowhair" : "/d/obj/magic/hyellow",
         "orangehair" : "/d/obj/magic/horange",
         "redhair" : "/d/obj/magic/hred",
       ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{
  object ob;

  ::init();
  add_action("do_vendor_list", "list");
}
void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

