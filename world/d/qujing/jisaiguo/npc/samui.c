

inherit F_VENDOR_SALE;

void create()
{
  reload("jisaoguo_uncle_samui");
  set_name("萨米儿大叔", ({"uncle samui","samui"}));
  set("shop_id", ({"uncle", "samui"}));

  set("gender", "男性" );
  set("age", 65);
  set("long", "一位光头小胡子，黄发蓝眼睛的老人，很风趣的样子。\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "peaceful");
  set("per", 15);
  set("vendor_goods", ([
        "roubing": "/d/obj/food/roubing",
        "yangtui": "/d/qujing/jisaiguo/obj/yangtui",
        "jiunang": "/d/obj/food/jiunang",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/qujing/jisaiguo/obj/changpao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) { 
                case 0:
                say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来歇歇脚，尝尝我烤的羊肉！\n");
                        break;
		case 1:
		say( name()+"热情的说：远方的客人，请进，请进！\n");
		break;
		case 2:
		say( name()+"说：来来来，新疆的烤羊肉，喷香的羊肉！\n");
		break;
        }
}

