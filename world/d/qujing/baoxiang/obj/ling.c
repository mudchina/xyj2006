// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("¾üÁîÅÆ", ({"junling pai", "pai"}));
  set_weight(1100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "Ö§");
    set("long", @LONG

  £¯£Ü
£ü    £ü
£ü ¾ü £ü
£ü    £ü
£ü Áî £ü
£ü    £ü
£ü ÅÆ £ü
£ü    £ü
£ü    £ü
 £­£­£­

LONG);

    set("value", 200000);
  }
  set("no_get",1);
  set("no_drop",1);
  set("no_sell",1);
  set("no_give",1);
  setup();
}

