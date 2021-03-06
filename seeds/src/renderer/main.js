import Vue from 'vue'
import axios from 'axios'

import App from './App'
import router from './router'
import store from './store'
// element-ui
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
import { ipcRenderer } from 'electron'
Vue.use(ElementUI)

if (!process.env.IS_WEB) Vue.use(require('vue-electron'))
Vue.http = Vue.prototype.$http = axios
Vue.config.productionTip = false
ipcRenderer.send('startServer')

/* eslint-disable no-new */
new Vue({
  el: '#app',
  components: { App },
  router,
  store,
  template: '<App/>'
}).$mount('#app')
