package com.example.chapter22.domain;

import com.example.chapter22.web.User;
import io.swagger.annotations.*;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@Api(tags = "用户管理")
@RestController
@RequestMapping("/user")
public class UserController {
    static Map<Long, User> map = Collections.synchronizedMap(new HashMap<Long,User>());

    /**
     * 处理/user的get请求，返回user列表
     * @return
     */
    @GetMapping("/")
    @ApiOperation(value = "获取用户列表")
    public List<User> getUserList() {
        List<User> res = new ArrayList<>(map.values());
        return res;
    }

    /**
     * 处理/user的post请求
     * @param user 用户信息，这里提交的是json数据，所以用@RequestBody注解转化一下
     * @return
     */
    @PostMapping("/")
    @ApiOperation(value = "新增用户")
    @ApiImplicitParam(paramType = "json", dataType = "User", name = "user", value = "新增用户信息", required = true)
    public String postUser(@RequestBody User user) {
        map.put(user.getId(), user);
        return "success";
    }

    /**
     * 处理/user/id的get请求
     * @param id 用户id
     * @return
     */
    @GetMapping("/{id}")
    @ApiOperation(value = "获取一个用户")
    @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1")
    public User getUser(@PathVariable Long id) {
        return map.get(id);
    }

    /**
     * 处理/user/id的put请求(更新操作)
     *@param id 用户id
     * @param user 用户信息，这里提交的是json数据，所以用@RequestBody注解转化一下
     * @return
     */
    @PutMapping("/{id}")
    @ApiOperation(value = "更新用户")
    @ApiImplicitParams({
            @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1"),
            @ApiImplicitParam(paramType = "json", dataType = "User", name = "user", value = "更新的用户信息", required = true)
    })
    @ApiResponses({
            @ApiResponse(code = 200, message = "更新用户信息成功"),
            @ApiResponse(code = 404, message = "请求路径错误")
    })
    public String putUser(@PathVariable Long id, @RequestBody User user) {
        User u = map.get(id);
        u.setAge(user.getAge());
        u.setName(user.getName());
        map.put(id, u);
        return "success";
    }

    /**
     * 处理/user/id的delete请求
     * @param id 用户id
     * @return
     */
    @DeleteMapping("/{id}")
    @ApiOperation(value = "删除一个用户")
    @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1")
    public String deleteUser(@PathVariable Long id) {
        map.remove(id);
        return "success";
    }
}
