package main
import (
	// "fmt"
	// "github.com/gin-gonic/gin"
	"ginrun/router"
	"ginrun/utils"
)
func main() {
	// r := gin.Default()
	// r.GET("/ping", func(c *gin.Context){
	// 	c.JSON(200, gin.H{
	// 		"message": "pong",
	// 	})
	// })
	// r.Run(":8081")
	utils.InitConfig()
	utils.InitMySQL()
	r := router.Router()
	r.Run(":8081")
}