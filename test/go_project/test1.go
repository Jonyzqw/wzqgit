package main

import (
 "fmt"
//  "time"
 "reflect"
 "log"
 "io/ioutil"
 "bytes"
 "encoding/gob"
 "encoding/json"
 "unsafe"
 "net/http"
//  "sync"
)
//1、判断nil和空切片的初始化内存指向是否相同
func test1() {
	var s1 []int
	s2 := make([]int,0)
	s4 := make([]int,0)
	
	fmt.Printf("s1 pointer:%+v, s2 pointer:%+v, s4 pointer:%+v, \n", *(*reflect.SliceHeader)(unsafe.Pointer(&s1)),*(*reflect.SliceHeader)(unsafe.Pointer(&s2)),*(*reflect.SliceHeader)(unsafe.Pointer(&s4)))
	fmt.Printf("%v\n", (*(*reflect.SliceHeader)(unsafe.Pointer(&s1)))==(*(*reflect.SliceHeader)(unsafe.Pointer(&s2))))
	fmt.Printf("%v\n", (*(*reflect.SliceHeader)(unsafe.Pointer(&s2))).Data==(*(*reflect.SliceHeader)(unsafe.Pointer(&s4))).Data)

}
//2、 字符串转成byte数组，会发生内存拷贝吗？(下面就不会)
func test2() {
    s1 := "abc"
    s2 := *(*reflect.StringHeader)(unsafe.Pointer(&s1))
    s3 := *(*[]byte)(unsafe.Pointer(&s2))
    fmt.Printf("s1.type:%p, s2.type:%p, s3.type:%p\n", &s1, &s2, &s3)
}
//3、翻转含有中文、数字、英文字母的字符串
	// "你好abc啊哈哈"
func test3() {
	reverse := func (s []rune)[]rune{
		for i,j :=0 , len(s)-1;i<j;i, j = i+1, j-1 {
			s[i], s[j] = s[j], s[i]
		} 
		return s
	}
	str := "你好abc啊哈哈"
	res := reverse([]rune(str))
	fmt.Printf("反转后的字符串为：%v\n", string(res))
}
//4、不能对未初始化的map复制，会报错 panic: assignment to entry in nil map
func test4() {
	// ma := make(map[int]int)
	var ma map[int]int
	ma[1] = 1
	fmt.Printf("%+v\n", ma[1])
}
//5、不同协程对map并发操作不用加锁也能实现安全问题。
// func test5() {
// 	var m sync.Map

// 	go func1() {
// 		for {
// 			vv, ok := m.Load(1) // 修正：声明 vv 和 ok 变量
// 			fmt.Println(vv, ok)
// 			time.Sleep(time.Second) // 修正：添加延迟以避免无限循环
// 		}
// 	}

// 	go func2() {
// 		for {
// 			m.Store(1, "2") // 存储的值应该与 Load 的键的类型匹配
// 			time.Sleep(time.Second) // 修正：添加延迟以避免无限循环
// 		}
// 	}
	
// 	// 使用 sync.WaitGroup 来等待 goroutine 完成
// 	var wg sync.WaitGroup
// 	wg.Add(2)
// 	go func() {
// 		defer wg.Done()
// 		func1()
// 	}()
// 	go func() {
// 		defer wg.Done()
// 		func2()
// 	}()
// 	wg.Wait()
// }
//6、json包变量不加tag会怎么样？(tag只用于取别名，json格式化必须首字母大写的key)
func test6() {
	type J struct{
		a string
		b string `json:"B"`
		C string 
		D string `json:"DD"`
	}
	j := J{
		a : "1",
		b : "2",
		C : "3",
		D : "4",
	}
	jj,_ := json.Marshal(j)
	fmt.Printf("json转换前:%v\n", j)
	fmt.Printf("json转换后:%v\n", string(jj))
}
//7、reflect（反射包）如何获取字段tag​？为什么json包不能导出私有变量的tag？
func test7(){
	type J struct {
		a string //小写无tag
		b string `json:"B"` //小写+tag
		C string //大写无tag
		D string `json:"DD" otherTag:"good"` //大写+tag
	}
	printTag := func(stru interface{}){
		t := reflect.TypeOf(stru).Elem();
		for i := 0;i<t.NumField();i++{
			fmt.Printf("结构体内第%v个字段 %v 对应的json tag是 %v , 还有otherTag？ = %v \n", i+1, t.Field(i).Name, t.Field(i).Tag.Get("json"), t.Field(i).Tag.Get("otherTag"))
		}
	}
	j := J{
		a: "1",
      	b: "2",
      	C: "3",
      	D: "4",
	}
	printTag(&j)
}

//自定义类型切片转字节切片和字节切片转回自动以类型切片
func test8() {
	type MyType struct{
		Value int
	}
	mySlice := []MyType{
		{Value: 1},
		{Value: 2},
		{Value: 3},
	}

	// 将自定义类型切片转换为字节切片
	var byteSlice []byte
	buf := new(bytes.Buffer)
	encoder := gob.NewEncoder(buf)
	if err := encoder.Encode(mySlice); err != nil {
		fmt.Println("Error encoding:", err)
		return
	}
	byteSlice = buf.Bytes()

	// 打印字节切片
	fmt.Println("Byte Slice:", byteSlice)

	// 将字节切片转回自定义类型切片
	var newSlice []MyType
	buf = bytes.NewBuffer(byteSlice)
	decoder := gob.NewDecoder(buf)
	if err := decoder.Decode(&newSlice); err != nil {
		fmt.Println("Error decoding:", err)
		return
	}

	// 打印自定义类型切片
	fmt.Println("Custom Type Slice:", newSlice)	
}
func webServer() {
	index := func(w http.ResponseWriter, r *http.Request){
		content, _ := ioutil.ReadFile("./index.html")
		// fmt.Fprintf(w, "C语言中文网")
		w.Write(content)
	}

	http.HandleFunc("/index", index)
	log.Fatal(http.ListenAndServe("127.0.0.1:8000", nil))
}
func main() {
	webServer();
}
 

// type SliceHeader struct {
// 	Data uintptr  //引用数组指针地址
// 	Len  int     // 切片的目前使用长度
// 	Cap  int     // 切片的容量
//    }