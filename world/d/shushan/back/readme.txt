
        Mudos V22pre11 for WIN95/NT with COM extension

目录
第一节    系统简介及部分改正的错误
第二节    LPC上的增强
第三节    COM extension语法
第四节    LPC和COM extension混合编程
附录一    V21版的mudlib转V22版时应注意的问题
附录二    Mudos v22pre11 with COM extension中的COM对象
附录三    Mudos v22pre11 with COM extension的架设


第一节    系统简介及部分改正的错误

	Mudos V22pre11 for WIN95/NT with COM extension ( 以下简称
pre11 with Com)由清华大学计算机系王文军，周霖在Mudos V22pre11的基
础上开发而成。比较原版本的Mudos V22pre11来说，这个版本的Mudos改正
了一些错误，增加了对COM对象的支持。
	COM( Component Object Model )是Microsoft公司提出的一个开放
的面向对象技术。在Mudos中加入COM的支持，主要是为了能运用一些已有的
成熟技术和资源，弥补Mudos本身的功能不足。关于COM的具体说明请参看OLE
编程的资料。
	
	Mudos V22pre11已经改正了V11版的不少错误，如get_host_by_addr的
返回值，对select函数的调用参数等等。但是作者将pre11移植到WIN32平台
后，在实际运行中发现还是有不少问题的。
    一个比较明显的问题是random函数的问题，WIN32平台的random本身是16
位的，运用到这个系统上时就会有范围不够的情况。在pre11 with com中已对
这个函数有改进，使得在LPC中的random是32位的。
    另一个是explode_string函数的bug,它在某些情况下会出现输出的array_t
部分元素没有符值的情况，在UNIX系统下也许不会有什么问题，但WIN32环境下
会导致Mudos当掉。作者对这个问题进行了圆满解决。
    另外有一些在中文处理，filesize中明显的bug等问题上都做了修改。
	
    当你在运行这个版本的mudos发现有什么问题时，或者需要原码的话，请与下面
的地址联系，我们会尽力给你解答的。

    酒井 BBS:         wwj  quake
    SMTH BBS:         wwj  KCN
    Internet EMAIL:   wwj@telekbird.com.cn
                      zhoulin@cai.cic.tsinghua.edu.cn



第二节    LPC上的增强

    Mudos V22版本相比V11版而言，LPC中新增了class类型，新增了一些
efunc，以下一一说明。

    V22版本中的class类型类似于C中struct,LPC的句法如下：

    class class_name {
	type member_name1;
	type member_name2;
	...
    };
    注意成员只能是变量。

    声明一个class对象时句法是

    class class_name object_name;

    使用对象之前应该先对对象初始化：
	
    object_name = new ( class class_name );

    在引用class对象的成员时应该使用 -> 符号。

    object_name -> member_name1 = 0;

    以下是一个LPC例子：

class npcdata {
    string name;
    int age;
};

class npcdata * data;

int set_npcdata(int id,string n,int a)
{
    if(nullp(data)){
        data=allocate(10);
    }
    data[id]=new(class npcdata);
    data[id]->name=n;
    data[id]->a=n;
}

    从使用效果来看，这个class类型与一个array的作用差不多。

    为支持class类型，增加了关键字new，前面已经有了介绍。
多了一个classp的efunc，用来判断一个参数是否class类型。

	


第三节    COM extension语法

    为了支持COM对象，pre11 with COM extension对class类型做了扩展。
	
    首先增加的是对class的成员函数的支持，有了这个特性之后，class类型
就和C++中的单个类比较相似了。下面给出一个带成员函数的class例子。

class ab
{
     int a;
     int add();
}

int ab::add()        // ab的成员函数 add()
{
    return a++;      // ab的成员变量 a++
}

class ab b;

useab()
{
    b=new(class ab);
    b->a=0;           // b->a is 0
    b->add();         // then b->a is 1
}
  
    由于成员函数的出现，有必要支持在成员函数中访问本class，因此增加了
一个this关键字，用它来指示当前的class变量。如int ab::add()就可以写成
int ab::add()
{
    return this->a++;
}
    当然this主要的作用是将class自己传给别的函数。

    增加了class成员函数的支持后，新增加了一个语法来定义COM对象。格式如下:

class class_name {
    member and member function ...
} = " com_class_id ";

    com_class_id是你要引用的com对象的CLSID或者ProgID，比如Microsoft
IE的HTML Viewer控件的CLSID是
		{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}
ProgID是 
		Microsoft Web Browser Control
    class_name是你所使用的Interface的名字，如HTML Viewer控件的一个接口是   
        IWebBrowser
    class 的member和member function都应该是这个接口的属性和方法。通过
VC中带的OLE/COM Viewer可以看到Microsoft Web Browser Control的IWebBrowser
的定义是这样的（部分）。。。

[
  uuid(EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B),       // 这就是那个CLSID
  helpstring("Web Browser interface"),         
  hidden,
  dual
]

dispinterface IWebBrowser {
    methods:

    [id(0xfffffdda), helpstring("Refresh the currently viewed page.")]
    void Refresh();                                // 一个方法 

    [id(0x00000068), helpstring("Navigates to a URL or file.")]
    void Navigate(                                 // 另一个方法   
         [in] BSTR URL, 
         [in] VARIANT* Flags, 
         [in] VARIANT* TargetFrameName, 
         [in] VARIANT* PostData, 
         [in] VARIANT* Headers);

    [id(0x000000ce), propget, helpstring("The horizontal position (pixels) of the frame window relative to the screen/container.")]
    long Left();                 
	// 虽然写在methods里，但由于progget属性，实际上还是认为是属性，
	// 这是读属性值的方法

    [id(0x000000ce), propput, helpstring("The horizontal position (pixels) of the frame window relative to the screen/container.")]
    void Left([in] long rhs);    
	// 虽然写在methods里，但由于progput属性，实际上还是认为是属性，
	// 这是写属性值的方法

	// 等等。。。
}

    变成LPC中可引用的class就该定义成：

class IWebBrowser {
    void Refresh();
    int Left;
} = "{EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B}"; 
    这个字符串可以另写为 Microsoft Web Browser Control
	
    考察上面这个定义，与标准的C++对象定义没什么大的差别。成员Refresh
方法基本上于MIDL的定义没什么变化，Left属性的类型变成了int，Navigate
方法没加进来，这是因为在LPC与COM间类型转换时不是所有类型的参数都可以用
的。

    目前的pre11 with COM extension支持以下类型转换：

    LPC中 int     与 COM中 int,long 互相转换。
    LPC中 string  与 COM中 BSTR     互相转换。
    LPC中 float   与 COM中 float    互相转换。
    LPC中 void    与 COM中 void     互相转换。
    LPC中 array   转成   COM中 IDispatch * 。
    LPC中 class   转成   COM中 IDispatch * 。
    LPC中 object  转成   COM中 IDispatch * 。
    LPC中 mapping 转成   COM中 IDispatch * 。

    这里"互相转换"的意思是支持该类型作为参数可以传递，也可以作为返回值，如
属性的类型。
    "转成"就意味着单向的，只能作为参数。

    对于无法转化的方法或属性，不要写在class的定义中。

    使用COM定义的class和普通的class相同，给出使用上面IWebBrowser的例子：

int UseIt()
{
    class IWebBrowser web;
    web=new (class IWebBrowser);
    web.Left=10;
    web.Refresh();
}

    这里使用IWebBrowser的目的是说明如何使用COM对象，事实上IWebBrowser
不能在Mudos上使用(Mudos是一个telnet服务器，用不着一个浏览器)。



第四节    LPC和COM extension混合编程

    pre11 with COM extension本身提供了几个COM对象用于与外面的程序通讯，
具体定义请看附录二，在以后的说明中我将会提到 IMudos,IMValue,IMNumber,
IMString,IMReal,IMClass,IMObject,IMArray,IMMapping,IMProgram,
IMFunction这几个接口。

    上一节介绍了在LPC中如何引用COM对象，下面将介绍一下如何在VC5中编写LPC
可用的COM对象。

    首先你得建立一个ATL com dll的工程，然后新增加一个ATL Class。当你把
这个class取名为CTest时，你所得到的接口(Interface)名就成了ITest。然后你
就可以往这个Interface中添加属性和方法。

    注意你所添加的属性类型只能是
	    int,BSTR,float
    你所添加的方法返回类型只能是
	    int,BSTR,float
    参数类型只能是
	    int,BSTR,float,IDispatch *
    对int,BSTR,float的处理和一般的COM一致。对IDispatch *的处理应该将它
传给IMValue对象，然后根据IMValue的Type()来GetExtend()取得相应类型的对象。
    比如LPC中定义的class成员函数

    int Test(int i,class CTest c);

    对应的COM对象成员函数就该是：
    MIDL  interface:  
        HRESULT Test([in] int i,[in] IDispatch *p,[out,retval] int *pVal);
    MIDL  dispinterface:
        int Test([in] int i,[in] IDispatch *p);
    C++:
        STDMETHOD(Test)(int i,IDispatch *p,int *pVal);
    在Test的实现时应该是这样的：

STDMETHODIMP CTest::Test(int i,IDispatch *p,int *pVal)
{
    // 这些接口的函数请查看生成的mudos.h
    if(!pVal)return S_FALSE;
    IMValue v(p);
    if(v.GetType()!=VP_CLASS)return S_FALSE;  
    IMClass c(v.GetExtend());

    // now use i,c
    // ...
    // return val in pVal
    return S_OK;
}
   
    你的对象可以声明两个方法作为事件响应：
    MIDL  interface:  
        HRESULT OnNewObject(IDispatch *p);
        HRESULT OnFreeObject();
    在C++中的实现是：
STDMETHODIMP CTest::OnNewObject(IDispatch *p)
{
    m_os=new IMudos(p);  // m_os是CTest的一个类型为IMudos *的成员变量
    return S_OK;
}
STDMETHODIMP CTest::OnFreeObject()
{
    delete m_os;
    return S_OK;
}
    这样在COM中就能使用IMudos的所有功能。
    


附录一    V21版的mudlib转V22版时应注意的问题

   如果你原来用的是MudOS v21.xx, 则升级至v22需要进行以下改动：

1、删除所有文件中在子类或外部使用的函数前面的private关键字。
   或者简单地删除所有函数前面的private就行了。
比如：/feature/attack.c中的：
private int attack()
....
改为 int attack()

类似的情况还有：
  /feature/action.c, treemap.c 等。

2、注意函数声明的类型要与函数实际类型相同
比如：
void myfunction();
....

int myfunction()
{
...
}

在v21里可能没问题，v22里就不能正确执行。

3、检查所有用到函数指针的地方。

v22不再支持形如(: ob, string :)这样的函数指针类型，

而需要改成：(: call_other, ob, string :)
比如在文件: /cmds/std/suicide.c 中第44行
     me->start_busy( (: __FILE__, "slow_suicide", me :));
必须改成：
     me->start_busy( (: call_other, __FILE__, "slow_suicide", me :));
才能正确使用。

类似的文件还有：
   es2: /std/weapon/sword.c blade.c axe.c ...
   xkx: /inherit/weapon/sword.c blade.c axe.c ...
等等。

4、修改origin.h
由于v22修改了origin函数的返回类型(从int改为string),
所以要修改origin.h:

#define ORIGIN_BACKEND       0x1
#define ORIGIN_DRIVER        0x1
#define ORIGIN_LOCAL         0x2
#define ORIGIN_CALL_OTHER    0x4
#define ORIGIN_SIMUL_EFUN    0x8
#define ORIGIN_CALL_OUT      0x10
#define ORIGIN_EFUN          0x20

改为：

#define ORIGIN_DRIVER        "driver"
#define ORIGIN_LOCAL         "local"
#define ORIGIN_CALL_OTHER    "call_other"
#define ORIGIN_SIMUL_EFUN    "simul"
#define ORIGIN_CALL_OUT      "call_out"
#define ORIGIN_EFUN          "efun"

5、SAVE_EXTENSION宏
在一些ES2，XKX版本中 /feature/save.c 中，save_file和load_file的代码上有
不同处理，其中一个加了SAVE_EXTENSION，另一个没有SAVE_EXTENSION。这会导致
securityd.c中的valid_write函数判存盘文件时出问题。原则上将 /feature/save.c
中的SAVE_EXTENSION去掉，然后修改securityd.c valid_write中判用户存盘的一
段代码改成：

      // Let user save their save file
      if( func=="save_object" ) {
              if(
                  sscanf(file, "/data/%*s") &&
                  (
                      ( file == (string) user->query_save_file() )||
                      ( file == (string) user->query_save_file() + ".o")
                  )
              )
              return 1;
      }

6、/cmds/arch/callouts.c
由于V22版的call_out_info()函数作了改动，不再返回call_out的参数，也就是说
返回的info[i]没有info[i][3]。因此需要改一下/cmds/arch/callouts.c，将对
info[i][3]的引用去掉。


附录二    Mudos v22pre11 with COM extension中的COM对象

mudos.idl文件
// Generated .IDL file (by the OLE/COM Object Viewer)
// 
// typelib filename: MUDOS.DLL
// Forward declare all types defined in this typelib
interface IMValue;
interface IMNumber;
interface IMString;
interface IMReal;
interface IMObject;
interface IMClass;
interface IMMapping;
interface IMArray;
interface IMBuffer;
interface IMProgram;
interface IMFunction;
interface IMudos;

[
  uuid(F64617C2-EA5A-11D1-B962-0080AD1480B3),
  version(1.0),
  helpstring("mudos v22pre11 Type Library")
]
library MUDOSLib
{
    // TLib : OLE Automation : {00020430-0000-0000-C000-000000000046}
    importlib("STDOLE2.TLB");

    [
      uuid(1B6ED8C0-EB38-11D1-BF0B-0000B4560A15),
      helpstring("MValue Class")
    ]
    coclass MValue {
        [default] interface IMValue;
        interface IMNumber;
        interface IMString;
        interface IMReal;
        interface IMObject;
        interface IMClass;
        interface IMMapping;
        interface IMArray;
        interface IMBuffer;
    };

    [
      odl,
      uuid(1B6ED7C8-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMValue Interface"),
      dual,
      oleautomation
    ]
    interface IMValue : IDispatch {
        [id(0x00000051), propget, helpstring("property Name")]
        HRESULT _stdcall Name([out, retval] BSTR* pVal);
        [id(0x00000052), propget, helpstring("property Type")]
        HRESULT _stdcall Type([out, retval] eVALUETYPE* pVal);
        [id(0x00000053), helpstring("method CreateNumber")]
        HRESULT _stdcall CreateNumber();
        [id(0x00000054), helpstring("method CreateString")]
        HRESULT _stdcall CreateString();
        [id(0x00000055), helpstring("method CreateReal")]
        HRESULT _stdcall CreateReal();
        [id(0x00000056), helpstring("method CreateArray")]
        HRESULT _stdcall CreateArray([in] int size);
        [id(0x00000057), helpstring("method CreateMapping")]
        HRESULT _stdcall CreateMapping();
        [id(0x00000058), propget, helpstring("property Extend")]
        HRESULT _stdcall Extend([out, retval] IDispatch** pVal);
    };

    typedef enum {
        VP_UNKNOW = 0,
        VP_NUMBER = 1,
        VP_STRING = 2,
        VP_REAL = 3,
        VP_OBJECT = 4,
        VP_ARRAY = 5,
        VP_MAPPING = 6,
        VP_CLASS = 7,
        VP_BUFFER = 8,
        VP_FUNCTION = 9
    } eVALUETYPE;

    [
      odl,
      uuid(1B6ED7C0-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMNumber Interface"),
      dual,
      oleautomation
    ]
    interface IMNumber : IDispatch {
        [id(0x00000001), propget, helpstring("property Number")]
        HRESULT _stdcall Number([out, retval] int* pVal);
        [id(0x00000001), propput, helpstring("property Number")]
        HRESULT _stdcall Number([in] int pVal);
    };

    [
      odl,
      uuid(1B6ED7C1-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMString Interface"),
      dual,
      oleautomation
    ]
    interface IMString : IDispatch {
        [id(0x0000000b), propget, helpstring("property String")]
        HRESULT _stdcall String([out, retval] BSTR* pVal);
        [id(0x0000000b), propput, helpstring("property String")]
        HRESULT _stdcall String([in] BSTR pVal);
    };

    [
      odl,
      uuid(1B6ED7C2-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMReal Interface"),
      dual,
      oleautomation
    ]
    interface IMReal : IDispatch {
        [id(0x00000015), propget, helpstring("property Real")]
        HRESULT _stdcall Real([out, retval] single* pVal);
        [id(0x00000015), propput, helpstring("property Real")]
        HRESULT _stdcall Real([in] single pVal);
    };

    [
      odl,
      uuid(1B6ED7C3-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMObject Interface"),
      dual,
      oleautomation
    ]
    interface IMObject : IDispatch {
        [id(0x0000001f), propget, helpstring("property ObjectName")]
        HRESULT _stdcall ObjectName([out, retval] BSTR* pVal);
        [id(0x00000020), propget, helpstring("property ObjectLoadTime")]
        HRESULT _stdcall ObjectLoadTime([out, retval] int* pVal);
        [id(0x00000021), propget, helpstring("property Environment")]
        HRESULT _stdcall Environment([out, retval] IMObject** pVal);
        [id(0x00000022), propget, helpstring("property ValueCount")]
        HRESULT _stdcall ValueCount([out, retval] int* pVal);
        [id(0x00000023), propget, helpstring("property Value")]
        HRESULT _stdcall Value(
                        [in] int id, 
                        [out, retval] IMValue** pVal);
    };

    [
      odl,
      uuid(1B6ED7C5-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMClass Interface"),
      dual,
      oleautomation
    ]
    interface IMClass : IDispatch {
        [id(0x00000033), propget, helpstring("property MemberCount")]
        HRESULT _stdcall MemberCount([out, retval] int* pVal);
        [id(0x00000034), propget, helpstring("property Member")]
        HRESULT _stdcall Member(
                        [in] int id, 
                        [out, retval] IMValue** pVal);
    };

    [
      odl,
      uuid(1B6ED7C6-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMMapping Interface"),
      dual,
      oleautomation
    ]
    interface IMMapping : IDispatch {
        [id(0x0000003d), propget, helpstring("property MappingCount")]
        HRESULT _stdcall MappingCount([out, retval] int* pVal);
        [id(0x0000003e), propget, helpstring("property MappingKeys")]
        HRESULT _stdcall MappingKeys([out, retval] IMArray** pVal);
        [id(0x0000003f), helpstring("method Query")]
        HRESULT _stdcall Query(
                        [in] BSTR sKey, 
                        [out, retval] IMValue** pVal);
        [id(0x00000040), helpstring("method Map")]
        HRESULT _stdcall Map(
                        [in] BSTR sKey, 
                        [in] IMValue* pVal);
    };

    [
      odl,
      uuid(1B6ED7C4-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMArray Interface"),
      dual,
      oleautomation
    ]
    interface IMArray : IDispatch {
        [id(0x00000029), propget, helpstring("property ItemCount")]
        HRESULT _stdcall ItemCount([out, retval] int* pVal);
        [id(0x0000002a), propget, helpstring("property Item")]
        HRESULT _stdcall Item(
                        [in] int id, 
                        [out, retval] IMValue** pVal);
    };

    [
      odl,
      uuid(1B6ED7C7-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMBuffer Interface"),
      dual,
      oleautomation
    ]
    interface IMBuffer : IDispatch {
    };

    [
      uuid(1B6ED8C1-EB38-11D1-BF0B-0000B4560A15),
      helpstring("MProgram Class")
    ]
    coclass MProgram {
        [default] interface IMProgram;
    };

    [
      odl,
      uuid(1B6ED7C9-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMProgram Interface"),
      dual,
      oleautomation
    ]
    interface IMProgram : IDispatch {
        [id(0x00000001), propget, helpstring("property FunctionCount")]
        HRESULT _stdcall FunctionCount([out, retval] int* pVal);
        [id(0x00000002), propget, helpstring("property Function")]
        HRESULT _stdcall Function(
                        [in] int id, 
                        [out, retval] IMFunction** pVal);
        [id(0x00000005), propget, helpstring("property FileName")]
        HRESULT _stdcall FileName([out, retval] BSTR* pVal);
    };

    [
      odl,
      uuid(1B6ED7CA-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMFunction Interface"),
      dual,
      oleautomation
    ]
    interface IMFunction : IDispatch {
        [id(0x00000001), propget, helpstring("property Name")]
        HRESULT _stdcall Name([out, retval] BSTR* pVal);
        [id(0x00000002), propget, helpstring("property ParamCount")]
        HRESULT _stdcall ParamCount([out, retval] int* pVal);
        [id(0x00000003), helpstring("method AddParam")]
        HRESULT _stdcall AddParam([in] IMValue* pVal);
        [id(0x00000004), helpstring("method ClearParam")]
        HRESULT _stdcall ClearParam();
        [id(0x00000005), propget, helpstring("property Ret")]
        HRESULT _stdcall Ret([out, retval] IMValue** pVal);
        [id(0x00000006), helpstring("method Apply")]
        HRESULT _stdcall Apply();
    };

    [
      uuid(1B6ED8C2-EB38-11D1-BF0B-0000B4560A15),
      helpstring("MFunction Class")
    ]
    coclass MFunction {
        [default] interface IMFunction;
    };

    [
      uuid(1B6ED8C3-EB38-11D1-BF0B-0000B4560A15),
      helpstring("Mudos Class")
    ]
    coclass Mudos {
        [default] interface IMudos;
    };

    [
      odl,
      uuid(1B6ED7CB-EB38-11D1-BF0B-0000B4560A15),
      helpstring("IMudos Interface"),
      dual,
      oleautomation
    ]
    interface IMudos : IDispatch {
        [id(0x00000001), propget, helpstring("property CurrentObject")]
        HRESULT _stdcall CurrentObject([out, retval] IMObject** pVal);
        [id(0x00000002), propget, helpstring("property CurrentProgram")]
        HRESULT _stdcall CurrentProgram([out, retval] IMProgram** pVal);
        [id(0x00000003), helpstring("method SetCommHook, pFunc is the function address.
int commhook(char *buf,int cursize,int maxsize,int user_id)")]
        HRESULT _stdcall SetCommHook([in] int pFunc);
        [id(0x00000004), helpstring("method Shutdown")]
        HRESULT _stdcall Shutdown();
        [id(0x00000005), propget, helpstring("property Users")]
        HRESULT _stdcall Users([out, retval] IMArray** pVal);
        [id(0x00000006), helpstring("method GetUser")]
        HRESULT _stdcall GetUser(
                        [in] int UserId, 
                        [out, retval] IMObject** pVal);
        [id(0x00000007), propget, helpstring("property HeartBeat")]
        HRESULT _stdcall HeartBeat([out, retval] int* pVal);
        [id(0x00000007), propput, helpstring("property HeartBeat")]
        HRESULT _stdcall HeartBeat([in] int pVal);
    };
};



对MUDOS COM对象的引用请用VC5的classwizard自动生成Mudos.h 和 Mudos.cpp，
然后在mudos.h中加上以下定义（这些值是IMValue::Type()的返回值）
#define        VP_UNKNOW        0
#define        VP_NUMBER        ( VP_UNKNOW  + 1 )
#define        VP_STRING        ( VP_NUMBER  + 1 )
#define        VP_REAL          ( VP_STRING  + 1 )
#define        VP_OBJECT        ( VP_REAL    + 1 )
#define        VP_ARRAY         ( VP_OBJECT  + 1 )
#define        VP_MAPPING       ( VP_ARRAY   + 1 ) 
#define        VP_CLASS         ( VP_MAPPING + 1 )
#define        VP_BUFFER        ( VP_CLASS   + 1 )
#define        VP_FUNCTION      ( VP_BUFFER  + 1 )


附录三    Mudos v22pre11 with COM extension的架设

    当你拿到Mudos v22pre11 for WIN95/NT with COM extension时，它是一个
zip文件，请用winzip展开，里面包含Mudos的Release版执行程序，Debug版执行程序，
这篇文档说明，一个LPC与COM混和编程的例子和一个测试用的es2 mudlib。

    Release版的Mudos执行程序在bin目录下，包含mudos.exe，mudos.dll两个文件。
将它们展出来后，首先执行 regsvr32 mudos.dll （regsvr32是一个COM对象登记用的
程序，一般放在win95的system目录下。〕，在mudos.exe相同目录下，新建一个文本文
件，取名为mudos.ini。内容如下

; mudos.ini
[init]
config=d:\mudlib\es2\config.es2  ; 这个是mudlib的配置文件路径，最好用全路径名
heartbeat=1000                   ; 这个是heartbeat的值，以毫秒计
addr_port=3990                   ; 如果需要启动addr_server，请加上此项。

[com]
{EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B}=c:\win\system\shdocvw.dll
;只有在这里定义过的CLSID或者ProgID才能在LPC中使用


    按照附录一中提供的mudlib修改方案将v21版的mudlib改成v22版的。
     
    如果你用的是WIN95，直接运行mudos.exe就会启动mud了。如果想把它搞成service
使得下次启动计算机时，mud就能自动运行，请执行 mudos install
    如果你用的是WINNT，请执行 mudos install，当它告诉你创建服务成功时，你就
可以在Control Panel中的Services找到mudos v22pre11 ...这个服务，然后选择start
就启动mud了。下次开机时会自动启动mud。

    运行时会在explorer的那个状态条的右端加上一个"小地球"的ICON，以此表明它正
在运行。用鼠标右键点击它，会出现一个菜单，可以选择restart或shutdown。
   
    Debug目录下是Debug版的Mudos，用法和Release一样。在调试COM对象时用Debug版
比较方便（Release版中把所有的异常都截掉了），

    TestSrc目录下是一个LPC与COM混和编程的例子。用VC5编译。

    Apple目录下是一个已编译好的苹果棋的例子，使用时先执行 regsvr32 apple.dll，
把duke.c拷到某个npc目录下，在mudos.ini的com字段中加入
    {B3C3EDB1-E735-11D1-BF0B-0000B4560A15}=1
    这样就可以clone duke来生成一个会下苹果棋的机器人－空色－了。


