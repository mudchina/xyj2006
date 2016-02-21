// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// hockshop.c
// modified by mon 2/28/98

inherit ROOM;

string *sell_msg = ({
     "ÆÆÆÆÀÃÀÃ£¬Ò»ÎÄ²»Öµ",
     "ÖÊµØµÍÁÓ£¬ÄÑ¿´Ö®¼«",
     "ÓÖÔàÓÖÆÆ£¬³ôÆøÑ¬Ìì",
});

object shop_box;

int query_max_items() {return 100;}
string get_name(string str);

void init()
{
   add_action("do_value", "value");
   add_action("do_pawn", "pawn");
   add_action("do_sell", "sell");
   add_action("do_retrieve", "retrieve");
   add_action("do_buy", "buy");
   add_action("do_list", "list");
   add_action("do_quit", "quit");

   set("no_clean_up", 1);
}

// find the shopbox object for this shop to hold sold items.
object findbox()
{
    if(shop_box && environment(shop_box)==this_object()) 
      return shop_box;

    shop_box=new(__DIR__"shopbox");
    shop_box->move(this_object());
    return shop_box;
}

string value_string(int value)
{
   if( value < 1 ) value = 1;
   else if( value < 100 )
     return chinese_number(value) + "ÎÄÇ®";
   else
     return chinese_number(value/100) + "Á½°×Òø"
        + (value%100? "ÓÖ" + chinese_number(value%100) + "ÎÄÇ®": "");
}

void pay_player(object who, int amount)
{
   object ob;

   if( amount < 1 ) amount = 1;
   if( amount/100 ) {
     ob = new(SILVER_OB);
     ob->set_amount(amount/100);
     if(!ob->move(who))
       ob->move(environment(who));
     amount %= 100;
   }
   if( amount ) {
     ob = new(COIN_OB);
     ob->set_amount(amount);
     if(!ob->move(who))
       ob->move(environment(who));
   }
}

int do_value(string arg)
{
   object ob;
   int value, sale;

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("ÄãÒªÄÃÊ²Ã´ÎïÆ·¸øµ±ÆÌ¹À¼Û£¿\n");

   if( ob->query("money_id") )
     return notify_fail("ÕâÊÇ¡¸Ç®¡¹£¬ÄãÃ»¼û¹ıÂğ£¿\n");

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value) printf("%sÒ»ÎÄ²»Öµ¡£\n", ob->query("name"));
   else 
     printf("%s¼ÛÖµ%s¡£\nÈç¹ûÄãÒªµäµ±(pawn)£¬¿ÉÒÔÄÃµ½%s¼°Ò»ÕÅµ±Æ±¡£\nÈç¹ûÂô¶Ï(sell)£¬¿ÉÒÔÄÃµ½%s¡£\n",
        ob->query("name"), value_string(value),
     value_string(value * 15 / 100), value_string(value * 20 / 100));

   return 1;
}

int do_pawn(string arg)
{
   object ob, stamp_ob;
   int value, sale;
   string obj_file;
   int  i;

   if( this_player()->is_busy() )
     return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("ÄãÒªµäµ±Ê²Ã´ÎïÆ·£¿\n");

   if( ob->query("money_id") )   return notify_fail("ÄãÒªµ±¡¸Ç®¡¹£¿\n");

   if( ob->query("material") == "ice" )
     return notify_fail("ÕÆ¹ñµÄËµ£º±ùµÄ¶«Î÷ÎÒÃÇÕâÀïÃ»·¨´æ·Å¡£\n");
   //cuz ice melts, will cause problem, so disabled...weiqi, 970930.

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value || value < 10) return notify_fail("ÕâÑù¶«Î÷²»ÖµÇ®¡£\n");
        if(ob->query("no_sell"))
      return notify_fail("ÕâÑù¶«Î÷²»ÄÜÂòÂô¡£\n");

   write("ÕÆ¹ñµÄ³ªµÀ£º"+ sell_msg[random(sizeof(sell_msg))] +
     ob->query("name") + "Ò»" + ob->query("unit") + "£¬Ñº"+
     value_string(value*15/100)+ "¡£\n");
   message_vision("$N°ÑÉíÉÏµÄ" + ob->query("name") + "ÄÃ³öÀ´µäµ±ÁË"
       + value_string(value * 15 / 100) + "¡£\n", this_player());

        stamp_ob = new("/obj/stamps");

   stamp_ob->set_temp("file", ob);
     stamp_ob->set_temp("value", value*15/100);
   stamp_ob->set_temp("player", this_player()->query("id"));
   stamp_ob->set_temp("long_1", this_player()->name()+"µäµ±" +
      ob->query("name") + "Ò»" + ob->query("unit") +
      "Æı£¬ÆÆÀÃÈ±Ëğ²»¿°¡£");
        stamp_ob->set_temp("long_2", "Êê»ØÓ¦¸¶"+
     value_string(value*70/100)+"Õû£¬Ò»ÊÖ½»Ç®£¬Ò»ÊÖ½»»õ¡£");

   this_player()->start_busy(1);
     pay_player(this_player(), value * 15 / 100);
   stamp_ob->move(this_player());

   //destruct(ob);
   ob->move(findbox());

   return 1;
}

int do_sell(string arg)
{
   object ob;
   int value, sale;
   string obj_file;
   int i, oldnum;
   string index;

   if( this_player()->is_busy() )
     return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("ÄãÒªÂô¶ÏÊ²Ã´ÎïÆ·£¿\n");

   if( ob->query("money_id") )   return notify_fail("ÄãÒªÂô¡¸Ç®¡¹£¿\n");
   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;
   if( !value ) return notify_fail("ÕâÑù¶«Î÷²»ÖµÇ®¡£\n");
        if(ob->query("no_sell"))
      return notify_fail("ÕâÑù¶«Î÷²»ÄÜÂòÂô¡£\n");

   if( ob->query("material") == "ice" )
     return notify_fail("ÕÆ¹ñµÄËµ£º±ùµÄ¶«Î÷ÎÒÃÇÕâÀïÃ»·¨´æ·Å¡£\n");
   //cuz ice melts, will cause problem, so disabled...weiqi, 970930.

   write("ÕÆ¹ñµÄ³ªµÀ£º"+ sell_msg[random(sizeof(sell_msg))] +
     ob->query("name") + "Ò»" + ob->query("unit") + "£¬µ±"+
        value_string(value*20/100)+ "¡£\n");
   message_vision("$N°ÑÉíÉÏµÄ" + ob->query("name") + "Âôµô¡£\n",
     this_player());

        index=ob->query("name")+"("+ob->query("id")+")";

   if(!findbox()->query_temp("goods/"+index) ){
           findbox()->set_temp("goods/"+index, ob);
      findbox()->set_temp("numbers/"+index, 1);
      ob->move(findbox());
   }
   else {
      oldnum = findbox()->query_temp("numbers/"+index);
           findbox()->set_temp("numbers/"+index, oldnum+1);
      destruct(ob);
   }

   this_player()->start_busy(1);
     pay_player(this_player(), value * 20 / 100);

   return 1;
}

int do_retrieve(string arg)
{
   object ob;
   int value, afford;
   object pawn_ob;

   if( this_player()->is_busy() )
     return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("ÄãÒªÊê»ØÊ²Ã´ÎïÆ·¡£\n");

   if( ob->query("id") != "pawn stamp")
      return notify_fail("ÄãÒªÓÃµ±Æ±²ÅÄÜÊê»ØÎïÆ·¡£\n");

   value = ob->query_temp("value");
   if(!value) 
      return notify_fail("ÓÃ¿Õ°×µ±Æ±À´ÊêÎï£¬¹âÌì»¯ÈÕÖ®ÏÂÏë´ò½Ù²»³É£¡\n");

   if( !(afford = this_player()->can_afford(value)) )  {
      return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÇ®À´Êê»Ø¡£\n");
   }
   else if( afford == 2 )
       return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄÁãÇ®£¬¶øÒøÆ±ÓÖÃ»ÈËÕÒµÃ¿ª¡£\n");

   if( ob->query_temp("player") != this_player()->query("id"))
      return notify_fail("ÓÖ²»ÊÇÄãµ±µÄ£¬Ïë³Ã»ğ´ò½Ù°¡£¡\n");

   pawn_ob = ob->query_temp("file");
   if(!pawn_ob) {
     destruct(ob);
     return notify_fail
       ("ÕÆ¹ñµÄ¾ªµÀ£ºÔã¸â£¡ÄãÒªµÄ¶«Î÷ÕÒ²»×ÅÁË¡£\n");
        }

   if(!pawn_ob->move(this_player())) return 0;
   destruct(ob);

   write("ÕÆ¹ñµÄ³ªµÀ£º"+ sell_msg[random(sizeof(sell_msg))] +
     pawn_ob->query("name") + "Ò»" + pawn_ob->query("unit") + "£¬ÊêÒø"+
      value_string(value)+ "¡£\n");
   message_vision("$NÓÃµ±Æ±Êê»ØÒ»"+pawn_ob->query("unit")+
      pawn_ob->query("name")+"¡£\n", this_player());

        this_player()->start_busy(1);
   this_player()->pay_money(value);
   this_player()->save();

    return 1;
}


int do_list(string arg)
{
   mapping goods;
   string list, *name;
   int i,turn=0;
   string tlist;
   object me=this_player();

   if( !mapp(goods = findbox()->query_temp("goods")) )
     return notify_fail("µ±ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎ»õÎï¿ÉÂô¡£\n");
   name = keys(goods);
   if(!sizeof(goods)) 
     return notify_fail("µ±ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎ»õÎï¿ÉÂô¡£\n");

   if( !arg )   {
      list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n";
//      write(list);
      i=sizeof(goods);
      while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
        //mon 2/4/98 because some items may destruct themselves
        //after being sold.

        tlist = get_name(name[i]);
        ++turn;
        list += sprintf("%-3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn, tlist,
          value_string(goods[name[i]]->query("value")),
          chinese_number(findbox()->query_temp("numbers/"+name[i])),
          goods[name[i]]->query("unit") );
         
      }
       me->start_more(list);
   }
   else if( arg == "book" )  {
     turn=0;
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }

           if( mapp(goods[name[i]]->query("skill")) )   {
           tlist = get_name(name[i]);
           ++turn;
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "drug" )  {
     turn=0;
     list = "";
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("drug_type") )   {
      	   ++turn;
           tlist = get_name(name[i]);
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "axe" || arg == "blade" || arg == "dagger" || 
   arg == "fork" || arg == "hammer" || arg == "spear" || arg == "mace" || arg == "rake" ||
   arg == "staff" || arg == "stick" || arg == "sword" || arg == "whip" ||
   arg == "throwing" )  {
     list = "";
     turn=0;
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }

      if( goods[name[i]]->query("skill_type") == arg )   {
      	   ++turn;
           tlist = get_name(name[i]);
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n", turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "archery" )  {
     list = "";
     turn=0;
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("apply/skill_type") == arg )   {
      	   ++turn;
           tlist = get_name(name[i]);
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }
   else if( arg == "armor" || arg == "boots" || arg == "cloth" ||
    arg == "finger" || arg == "hands" || arg == "head" || arg == "neck" ||
    arg == "shield" || arg == "surcoat" || arg == "waist" ||
    arg == "wrists" )   {
     list = "";
     turn=0;
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( goods[name[i]]->query("armor_type") == arg )   {
      	   ++turn;
           tlist = get_name(name[i]);
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }
   else   {
     list = "";
     turn=0;
     i=sizeof(goods);
     while(i--) {
             if(!goods[name[i]]) {
          findbox()->delete_temp("numbers/"+name[i]);
          findbox()->delete_temp("goods/"+name[i]);
          continue;
             }
      if( member_array(arg, goods[name[i]]->parse_command_id_list()) != -1 )   {
      	   ++turn;
           tlist = get_name(name[i]);
           list += sprintf("%3d %-30s£º%-20s£º»¹Ê£%s%s\n",turn,tlist,
             value_string(goods[name[i]]->query("value")),
             chinese_number(findbox()->query_temp("numbers/"+name[i])),
             goods[name[i]]->query("unit") );
      }
     }
      if( list == "" )
      write("µ±ÆÌÄ¿Ç°Ã»ÓĞÕâÖÖ»õÆ·£®\n");
      else {
   list = "Äã¿ÉÒÔ¹ºÂòÏÂÁĞÕâĞ©¶«Î÷£º\n"+list;
   me->start_more(list);
      }
   }

   return 1;
}


int do_buy(string arg)
{
   mapping goods;
   string *name;
   string fname;
   object obj_file, ob;
   int value, oldnum, afford, order;
   int i, j;
   object* inv;
   string arg1, arg2;

   if( this_player()->is_busy() )
     return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");

   if( !arg )  {
      write("Ö¸Áî¸ñÊ½£ºbuy <Ä³Îï>\n");
      return 1;
   }

   // players are used to the "buy sth from sb" format.
   if( sscanf(arg, "%s from %s", arg1, arg2) == 2 )   {
     arg = arg1;
   }

   if( sscanf(arg, "%s %d", fname, order) != 2 )   {
     fname = arg;
     order = 1;
   }

   if( !mapp(goods = findbox()->query_temp("goods")) )
     return notify_fail("µ±ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎ»õÎï¿ÉÂô¡£\n");
   name = keys(goods);
   if(!sizeof(goods)) 
     return notify_fail("µ±ÆÌÄ¿Ç°Ã»ÓĞÈÎºÎ»õÎï¿ÉÂô¡£\n");

   j = 0;
   i=sizeof(name);
   while(i--) {
          if(!goods[name[i]]) continue;
     if( member_array(fname, 
         goods[name[i]]->parse_command_id_list()) != -1 )  {
        j++;    
     }
     if( j == order )   {
       obj_file = goods[name[i]];
          value = obj_file->query("value"); 
          if( !(afford=this_player()->can_afford(value)) )  {
             write("ÄãÃ»ÓĞ×ã¹»µÄÇ®¡£\n");
             return 1; 
          }
          else if( afford == 2 )  {
              write("ÄãÃ»ÓĞ×ã¹»µÄÁãÇ®£¬¶øÒøÆ±ÓÖÃ»ÈËÕÒµÃ¿ª¡£\n");
             return 1;
          }

       ob = new( base_name( obj_file ) ); 
       ob->set_name(obj_file->query("name"),
         obj_file->parse_command_id_list());
         //so that the bought item would be the
         //same as the one on sale.

          if(!ob->move(this_player()))
         return 0;

          this_player()->start_busy(1);

       arg = obj_file->query("name")+
         "("+obj_file->query("id")+")";
          oldnum = findbox()->query_temp("numbers/"+arg);
          if(oldnum == 1)  {
              destruct(obj_file);
           findbox()->delete_temp("numbers/"+arg);
           findbox()->delete_temp("goods/"+arg);
          }
          else    {
           findbox()->set_temp("numbers/"+arg, oldnum-1); 
       }

          this_player()->pay_money(value);
     
          message_vision("$NÏòµ±ÆÌÂòÏÂÒ»" +
        ob->query("unit") + ob->query("name") + "¡£\n", this_player() );

       this_player()->save();
       return 1;
     }
   }

   write("µ±ÆÌÀïÃ»ÓĞÕâÖÖ»õÆ·¡£\n");

   return 1;
}

int do_quit()
{
   this_player()->move("/cmds/std/quitroom");
   return 1;
}

// no clean up at hockshop to prevent items lose.
int clean_up()  
{
      return 0;
}

// strip away ansi color code.
// mon 5/7/98
string get_name(string str)
{
    string str1, str2;

    while(sscanf(str,"%s%*sm%s",str1,str2)==3)
   str=str1+str2;
    return str;
}
