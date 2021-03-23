package com.example.chapter23.web;

import com.example.chapter23.domain.User;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.*;

@Api(tags = "用户管理")
@RequestMapping("/user/")
@RestController
public class UserController {
    static Map<Long, User> map = Collections.synchronizedMap(new HashMap<Long, User>());

    /**
     * 处理/user的get请求, 返回user列表
     *
     * @return
     */
    @GetMapping("/")
    @ApiOperation(value = "获取用户列表")
    public List<User> getUserList() {
        return new ArrayList<>(map.values());
    }

    @PostMapping("/")
    @ApiOperation(value = "新增用户信息")
    @ApiImplicitParam(paramType = "json", dataType = "User", name = "user", value = "新增用户信息", required = true)
    public String postUser(@Valid @RequestBody User user) {
        map.put(user.getId(), user);
        return "success";
    }

    @GetMapping("/{id}")
    @ApiOperation(value = "获取一个用户")
    @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1")
    public User getUser(@PathVariable Long id) {
        return map.get(id);
    }

    @PutMapping("/{id}")
    @ApiOperation(value = "更新用户信息")
    @ApiImplicitParams({
            @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1"),
            @ApiImplicitParam(paramType = "json", dataType = "User", name = "user", value = "新增用户信息", required = true)
    })
    public String putUser(@PathVariable Long id, @Valid @RequestBody User user) {
        User u = map.get(id);
        u.setName(user.getName());
        u.setAge(user.getAge());
        u.setEmail(user.getEmail());
        map.put(id, user);
        return "success";
    }

    @DeleteMapping("/{id}")
    @ApiOperation(value = "删除一个用户")
    @ApiImplicitParam(paramType = "path", dataType = "Long", name = "id", value = "用户编号", required = true, example = "1")
    public String deleteUser(@PathVariable Long id) {
        map.remove(id);
        return "success";
    }
}