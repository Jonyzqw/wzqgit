package utils
import(
	"github.com/spf13/viper"
	"fmt"
	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	// "ginrun/models"
)
var DB *gorm.DB
func InitMySQL(){
	DB, _ = gorm.Open(mysql.Open(viper.GetString("mysql.dns")), &gorm.Config{})
	fmt.Println("mysql init")
	// user := models.UserBasic{}
	// DB.Find(&user)
	// fmt.Println(user)
}
func InitConfig(){
	viper.SetConfigName("app")
	viper.AddConfigPath("config")
	err := viper.ReadInConfig()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println("config app init")
	
}