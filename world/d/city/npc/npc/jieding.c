inherit NPC;

int give_book ();

int create()
{
  set_name("½ê¶¥Ð¡É®", ({"jieding xiaoseng","xiaoseng", "seng"}));
  set("long", "Ò»Î»Ð¡ºÍÉÐ£¬Í·ÉÏÈ«ÊÇ½ê°Ì¡£\n");

  set("gender", "ÄÐÐÔ");
  set("attitude", "peaceful");
  set("class", "bonze");
  set("age", 15);
  set("str", 20);
  set("int", 30);
  set("per", 18);
  set("con", 20);
  set("max_kee", 400);
  set("max_sen", 400);
  set("max_force", 300);
  set("force", 300);
  set("force_factor", 10);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 10);
  set("combat_exp", 50000);
  set("daoxing", 80000);


  set("chat_chance", 5);
  set("chat_msg", ({
    "½ê¶¥Ð¡É®Ì¾µÀ£º³¤°²ËäºÃÈ´ÊÇ·²³¾£¬ÈôÓûÇóÕý¹û½ðÉíÐëÈ¥Î÷ÌìÈ¡¾­Ò²£¡\n",
    (: random_move :)
  }));
  set("inquiry", ([
    "Î÷Ìì" : (: give_book :),
    "È¡¾­" : (: give_book :),
  ]) );

  set_skill("force", 50);
  set_skill("unarmed", 50);
  set_skill("dodge", 79);
  set_skill("parry", 79);
  set_skill("staff", 50);
  set_skill("lotusforce", 50);
  set_skill("lunhui-zhang", 79);
  set_skill("jienan-zhi", 50);
  set_skill("lotusmove", 79);
  map_skill("dodge", "lotusmove");
  map_skill("unarmed", "jienan-zhi");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "lotusforce");
  setup();
  add_money("silver", 5);
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/obj/cloth/sengxie")->wear();
  carry_object("/d/obj/books-nonskill/book-qujing");
  set("books", 3);
  setup();
}

int give_book ()
{
  object who = this_player();
  object book;

  if (query("books") <= 0)
  {
    command ("shake");
    return 1;
  }
  
  book = new ("/d/obj/books-nonskill/book-qujing");
  add("books",-1);
  message_vision ("½ê¶¥Ð¡É®¸ø$NÒ»±¾$n¡£\n",who,book);
  book->move(who);
  return 1; 
}
ÿ