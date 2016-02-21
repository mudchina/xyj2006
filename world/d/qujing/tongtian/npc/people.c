// by snowcat  11/22/1997

inherit NPC;

string *mnames = ({
  "³Â¿µ",
  "³ÂÂ»",
  "³ÂËİ",
  "³Âğ¯",
  "³ÂÊñ",
  "³Âìâ",
  "³Âê©",
  "³ÂóĞ",
  "³Â×Óò°",
  "³ÂÁú´ó",
  "³Â´óÍ·",
  "³ÂĞ¡¸ö",
  "³ÂÀÏ´ó",
  "³ÂÀÏ¶ş",
  "³ÂÀÏÈı",
  "³ÂÀÏËÄ",
  "³Â´ó²®",
  "³Â´óÊå",
  "³Â´ó¾Ë",
  "³Â´ó¸ç",
  "³Â´óÒ¯",
  "³Â¶ş²®",
  "³Â¶şÊå",
  "³Â¶ş¾Ë",
  "³Â¶ş¸ç",
  "³Â¶şÒ¯",
  "³ÂÈı²®",
  "³ÂÈıÊå",
  "³ÂÈı¾Ë",
  "³ÂÈı¸ç",
  "³ÂÈıÒ¯",
  "³ÂËÄ²®",
  "³ÂËÄÊå",
  "³ÂËÄ¾Ë",
  "³ÂËÄ¸ç",
  "³ÂËÄÒ¯",
});

string *fnames = ({
  "³ÂÄï",
  "³ÂÊÏ",
  "³ÂÆÅ",
  "³ÂÂè",
  "³ÂÉ©",
  "³ÂÉô",
  "³Â´óÄï",
  "³Â´óÆÅ",
  "³Â´óÂè",
  "³Â´óÉ©",
  "³Â´óÉô",
  "³Â¶şÄï",
  "³Â¶şÆÅ",
  "³Â¶şÂè",
  "³Â¶şÉ©",
  "³Â¶şÉô",
  "³ÂÈıÄï",
  "³ÂÈıÆÅ",
  "³ÂÈıÂè",
  "³ÂÈıÉ©",
  "³ÂÈıÉô",
  "³ÂËÄÄï",
  "³ÂËÄÆÅ",
  "³ÂËÄÂè",
  "³ÂËÄÉ©",
  "³ÂËÄÉô",
});

void create()
{
  string cloth;

  if (random(2))
  {
    int i = random(sizeof(mnames));
    set_name(mnames[i], ({"chen"}));
    set("gender", "ÄĞĞÔ");
    cloth = "/d/qujing/tongtian/obj/cloth";
  }
  else
  {
    int i = random(sizeof(fnames));
    set_name(fnames[i], ({"chen"}));
    set("gender", "Å®ĞÔ");
    cloth = "/d/qujing/tongtian/obj/skirt";
  }
  set("combat_exp", 1000+random(20000));
  set("age", 40+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  setup();
  carry_object(cloth)->wear();
}


