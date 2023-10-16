package router
import (
	"ginrun/service"
	"github.com/gin-gonic/gin"
)
func Router() *gin.Engine{
	r := gin.Default()
	r.GET("/index", service.GetIndex)
	r.GET("/user/getuserlist", service.GetUserList)
	return r
}