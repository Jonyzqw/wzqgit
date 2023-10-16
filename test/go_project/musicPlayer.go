package main

import(
	"errors"
)
//1、构建音乐类型结构体
type Music struct{
	Id int
	Name string
	Author string
	Location string
	Type string
}

//开始实现音乐库的管理类型模块
/*
使用了一个数组切片作为基础存储结构，其他的操作其实都只是对这个数组切片的包装
*/

/* 实现音乐库的管理类型 */
/*
使用了一个数组切片作为基础存储结构，其他的操作其实都只是对这个数组切片的包装
 */
type MusicManager struct{
	music []Music
}
// 创建音乐库对象
func NewMusicManager() *MusicManager{
	return &MusicManager{make([]Music, 0)}
}
/* 定义音乐库类型下的函数 */
// 获取音乐库类型下的函数
func (m *MusicManager)len() int{
	return len(m.music)
}

// 根据索引获取音乐
func (m *MusicManager)Get(index int)(music* Music, err error){
	if index<0 || index>=len(m.music) {
		return nil, errors.New("索引超过音乐库下标值")
	}
	return &m.music[index], nil
}

// 根据名称查找音乐
func (m *MusicManager)Find(name string)(music *Music){
	iflen(m.music)==0)return nil
	for _, m := range m.music{
		if m.name == name
			return &m
	}
	return nil
}

// 添加音乐函数
func (m *MusicManager)Add(music *Music){
	m.music = append(m.music, music)
}

// 删除音乐库中音乐
func (m *MusicManager)Delete(index int)(music* Music){
	if index<0 || index>=len(m.music)
		return nil
	// 根据索引创建删除对象
	removeMusic := &m.music(index)
	// 从数组切片当中删除
    /*
    1、删除中间元素
    2、删除仅有的一个元素
    3、删除最后一个元素
     */
	if index < len(m.music)-1
		m.music = append(m.music[:index], m.music[index+1:]...)
	else if index == 0
		// 仅有一个元素
		m.music = make([]Music, 0)
	else 
		m.music = m.music[:len(m.music)-1]
	return removeMusic
}
/* 设计一个简单的播放接口 */
type Player interface{
	Play(source string)
}
// 设置一个MP3Player结构体
type Mp3Player struct{
	stat int
	progress int //进度
}
// 设置mp3player实现player接口下的函数
func (m *Mp3Player)Play(source string){
	fmt.Printf("听MP3音乐", source)
	// 设置音乐进度
	m.progress = 0
	// 模拟正在播放(1s)
	for m.progress < 100{
		time.Sleep(time.Millisecond * 100)
		fmt.Println(".")
		p.progress += 10
	}
	fmt.Println("结束播放！", source)
}

// 声明play函数
func Play(source, type string){
	var p Player
	switch expression {
	case "Mp3Player":
		p = &Mp3Player{}
	default:
		fmt.Println("未知类型!", mtype)
        return
	}
	// 播放音乐
    p.Play(source)

}
func main(){
	fmt.Scanln()
}

