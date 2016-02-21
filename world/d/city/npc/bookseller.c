// ¿×·½ÐÖ, bookseller.
// 5-3-97, pickle

inherit F_VENDOR_SALE;

void create()
{
    reload("city_kongfang");
  set_name("¿×·½ÐÖ", ({ "kong fang", "kongfang", "kong", "fang", "bookseller", "seller", "vendor" }) );
  set("shop_id",({"kongfang","kong","fang","bookseller","seller"}));
  set("gender", "ÄÐÐÔ" );
  set("age", 37);
  set("title", "ÊéµêÀÏ°å");
  set("long","¿×Ðã²ÅÈë¾©¸Ï¿¼ÂäµÚ£¬ÅÌ²øÓÃ¾¡£¬ÎÞ·¨»¹Ïç£¬\n²»µÃÒÑÔÚ³¤°²¿ªÒ»¼ÒÊéµê¡£´«ËµËûÔøÓöÒìÈË£¬\nÑ§µÃÒ»Ð©·ÀÉíÖ®Êõ¡£\n");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 500);
  set_skill("parry", 600);
  set_skill("unarmed", 500);
  set_skill("jinghun-zhang", 500);
  set_skill("literate", 70);
  set("attitude", "friendly");
  map_skill("unarmed", "jinghun-zhang");
  set("str", 1000);
  set("rank_info/respect", "¿×Ðã²Å");
  set("per",25);
  set("vendor_goods", ([
//    "xiji": "/d/obj/books-nonskill/xiji",
//    "fuji": "/d/obj/books-nonskill/fuji",
//    "kunlun": "/d/obj/books-nonskill/kunlun",
   "chunqiu": "/d/obj/book/chunqiu",
   "jingang": "/d/obj/book/jingang",
   "shaolin": "/d/obj/book/parrybook2",
   "mihou": "/d/obj/book/mihou-book",
   "fumo": "/d/obj/book/forcebook2",
   "balei": "/d/obj/book/balei",
   "quanji": "/d/obj/book/boxing",
   "huajian": "/d/obj/book/westsword",
    "san": "/d/obj/book/san",
    "blade-book" : "/d/obj/book/basic_blade",
    "unarmed-book": "/d/obj/book/basic_unarmed",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say ÕâÎ»" + RANK_D->query_respect(ob) +"Çë½øÇë½ø¡£");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
	if (npc->query_temp(st)<10)
	  {
	  //  npc->add_temp(st,1);
	      // limit needed only for non-skills books
  	    return ::buy_object(who,item);
	  }
	else
	  {
	    return notify_fail(name()+"ËµµÀ£º¶Ô²»Æð£¬ÄúÀÏÒªµÄÊéÂôÍêÁË£¡ÄúµÈÏÂÒ»Åú½ø»õ°É¡£\n");
	  }
	//npc->add_temp("total_books", 1);
      }
      else
      {
	return notify_fail(name()+"ËµµÀ£ºÐ¡µê±¾Ð¡£¬½ñÈÕÒÔ½«´æ»õÂôÍêÁË¡£ÄúÀÏµÈÏÂÒ»Åú°É¡£\n");
      }
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
        message_vision("\nºöÈ»´ÓÃÅÍâ³å½øÀ´¸öÑ²Âß¹Ù±ø£¬¶Ô$N´óº°Ò»Éù¡°¸ÉÊ²Ã´£¿ÏëÉ±ÈËÄ±²ÆÃ´£¡\n\n",me);        

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

ÿ
