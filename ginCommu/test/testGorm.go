/**
* @Auth:ShenZ
* @Description:
* @CreateDate:2022/06/15 10:57:44
 */
 package main
 
 import (
	 "fmt"
	 "ginrun/models"
  
	 "gorm.io/driver/mysql"
	 "gorm.io/gorm"
 )
  
 func main() {
	 //gorm连接指定ip的数据库
	 db, err := gorm.Open(mysql.Open("root:123456@tcp(127.0.0.1:33306)/mysql?charset=utf8mb4&parseTime=True&loc=Local"), &gorm.Config{})
	 if err != nil {
		 panic("failed to connect database")
	 }
  
	 // 迁移 schema，用传入的模型格式更新一张表结构
	 //db.AutoMigrate(&models.Community{})
	 db.AutoMigrate(&models.UserBasic{})
	 //db.AutoMigrate(&models.Message{})
	 //db.AutoMigrate(&models.GroupBasic{})
	 //db.AutoMigrate(&models.Contact{})
  
	 // Create
	 user := &models.UserBasic{}
	 user.Name = "申专"
  
	 db.Create(user)
  
	 // // Read
	 fmt.Println(db.First(user, 1)) // 根据整型主键查找第一条记录
	 //db.First(user, "code = ?", "D42") // 查找 code 字段值为 D42 的记录
  
	 // Update - 将 product 的 price 更新为 200
	 db.Model(user).Update("PassWord", "1234")
	 // Update - 更新多个字段
	 //db.Model(&product).Updates(Product{Price: 200, Code: "F42"}) // 仅更新非零值字段
	 //db.Model(&product).Updates(map[string]interface{}{"Price": 200, "Code": "F42"})
  
	 // Delete - 删除 product
	 //db.Delete(&product, 1)
 }

// package main

// import (
// 	"/ginrun/models"
//   "fmt"
//   "gorm.io/gorm"
//   "gorm.io/driver/mysql"
  
// )
// // type userBasic struct{
// // 	gorm.Model
// // 	Name          string
// // 	PassWord      string
// // 	Phone         string `valid:"matches(^1[3-9]{1}\\d{9}$)"`
// // 	Email         string `valid:"email"`
// // 	Avatar        string //头像
// // 	Identity      string
// // 	ClientIp      string
// // 	ClientPort    string
// // 	Salt          string
// // 	// LoginTime     time.Time
// // 	// HeartbeatTime time.Time
// // 	// LoginOutTime  time.Time `gorm:"column:login_out_time" json:"login_out_time"`
// // 	IsLogout      bool
// // 	DeviceInfo    string
// // }

// // func (table* userBasic) TableName()string{
// // 	return "user_basic"
// // } 


// func main() {
//   db, err := gorm.Open(mysql.Open("root:123456@tcp(127.0.0.1:33306)/mysql?charset=utf8mb4&parseTime=True&loc=Local"), &gorm.Config{})
//   if err != nil {
//     panic("failed to connect database")
//   }

//   // 迁移 schema
//   db.AutoMigrate(&models.userBasic{})

//   // Create
//   user := &models.userBasic{}
//   user.Name = "zqwu"
//   db.Create(user)

//   // Read
//   // var product Product
//   fmt.Println(db.First(user, 1)) // 根据整型主键查找
// //   db.First(user, "code = ?", "D42") // 查找 code 字段值为 D42 的记录

//   // Update - 将 product 的 price 更新为 200
//   db.Model(user).Update("PassWord", "123456")
//   // Update - 更新多个字段
// //   db.Model(&product).Updates(Product{Price: 200, Code: "F42"}) // 仅更新非零值字段
// //   db.Model(&product).Updates(map[string]interface{}{"Price": 200, "Code": "F42"})

//   // Delete - 删除 product
// //   db.Delete(&product, 1)
// }