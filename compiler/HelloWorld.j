.class public HelloWorld
.super java/lang/Object 
.field public static a I
.field public static c I
.field public static b F
.field public static d F
.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 10
sipush 3
putstatic HelloWorld/a I
sipush 5
putstatic HelloWorld/c I
ldc 4.000000
putstatic HelloWorld/d F
getstatic HelloWorld/a I
getstatic HelloWorld/c I
iadd
getstatic HelloWorld/a I
getstatic HelloWorld/c I
isub
idiv
putstatic HelloWorld/c I
ldc 2.000000
putstatic HelloWorld/b F
getstatic HelloWorld/d F
getstatic HelloWorld/b F
fmul
putstatic HelloWorld/b F
return
.end method