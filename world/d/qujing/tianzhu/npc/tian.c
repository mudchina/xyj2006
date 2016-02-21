// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_tian_niu");
  set_name("甜妞", ({"tian niu", "tian", "niu"}));
  set("shop_id", ({"tianniu", "tian", "niu"}));
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 17);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "simao": "/d/qujing/tianzhu/obj/simao",
        "fengguan": "/d/qujing/tianzhu/obj/fengguan",
        "longguan": "/d/qujing/tianzhu/obj/longguan",
        "mukui": "/d/qujing/tianzhu/obj/mukui",
        "tiekui": "/d/qujing/tianzhu/obj/tiekui",
      ]) );

  setup();
  carry_object("/d/obj/misc/necklace")->wear();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/fengguan")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

int accept_object(object me, object ob)
  {
        object lw;
        lw=new("/u/mind/lwbook.c");
 //if((string)ob->query("name")=="民间货帽" )
 if(((string)ob->query("id")=="huomao")&&!userp(ob))
        {
         command("fool");
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
